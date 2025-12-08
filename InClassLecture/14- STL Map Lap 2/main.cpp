#include <iostream>
#include <map>
using namespace std;


struct Stock {
	string symbol;
	string name;
	double lastPrice;
};

class Portfolio {
	map<string, Stock> data;
public:
	bool addOrUpdate(const string& symbol, const string& name, double price) {
		auto it = data.find(symbol);

		if (it != data.end()) {
			it->second.name = name;
			it->second.lastPrice = price;
			return false; 
		}
		else {
			data[symbol] = { symbol, name, price };
			return true;
		}
	}
	
	bool contains(const string& symbol) const {
		cout << "Checking for " << symbol << " in portfolio" << endl;
		return data.find(symbol) != data.end();
	}

	bool remove(const string& symbol) {
		if (data.erase(symbol)) {
			cout << symbol << " removed from portfolio" << endl;
			return true;
		}
		else {
			return false;
		}
	}

	size_t size() const {
		return data.size();
	}

	void printAll() const {
		if (!data.empty()) {
			cout << "Symbol, Name, Last Price" << endl;
			for (const auto& pair : data) {
				cout << pair.first << " , " << pair.second.name << " , " << pair.second.lastPrice << endl;
			}
		}
		
	}

	double totalMarketValue(const map<string, int>& shareCount) const {
		double total = 0.0;

		for (const auto& pair : shareCount) {

			auto it = data.find(pair.first);
			if (it != data.end()) {
				total += it->second.lastPrice * pair.second;
			}
		}

		return total;
	}
};



int main() {

	Portfolio pf;
	pf.addOrUpdate("AAPL", "Apple Inc.", 170.25);
	pf.addOrUpdate("MSFT", "Microsoft Corp.", 402.11);
	pf.addOrUpdate("GOOGL", "Alphabet Inc.", 165.88);
	pf.addOrUpdate("NVDA", "NVDIA Corp.", 112.30);
	pf.addOrUpdate("AMZN", "Amazon.com Inc.", 185.44);


	pf.printAll();

	cout << "Size: " << pf.size() << endl;

	

	cout << boolalpha;
	cout << pf.contains("AAPL") << endl;

	map<string, int> shares = {
		{"AAPL", 10},
		{"GOOGL", 2},
		{"MSFT", 8},
		{"NVDA", 4},
		{"AMZN" , 2 },
	};

	cout << "Total market value: $" << pf.totalMarketValue(shares) << endl;

	pf.remove("GOOGL");
	pf.printAll();
	cout << "Total market value: $" << pf.totalMarketValue(shares) << endl;




	return 0;
}