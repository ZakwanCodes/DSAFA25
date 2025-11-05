#include <iostream>
#include <map>
using namespace std;

/*
void map_operations() {
	
	map<string, int> ageMap;

	ageMap["Bob"] = 20;
	ageMap["Sarah"] = 25;
	ageMap["John"] = 21;

	cout << ageMap["Bob"] << endl;

	if (ageMap.find("Peter") != ageMap.end()) {
		cout << "Key Sarah found" << endl;
	}
	else {
		cout << "key is not found" << endl;
	}

	for (const auto& pair : ageMap) {
		cout << pair.first << " , " << pair.second << endl;
	}

	for (auto it = ageMap.begin(); it != ageMap.end(); ++it) {
		cout << it->first << " , " << it->second << endl;
	}

	cout << "Size: " << ageMap.size() << endl;
} */



//create map with templates to store different data types
/*
template<typename KeyType, typename ValueType>
void printMap(map<KeyType, ValueType> &m) {
	for (const auto& pair : m) {
		cout << pair.first << " , " << pair.second << endl;
	}
}

template<typename KeyType, typename ValueType> 
bool containsKey(const map<KeyType, ValueType> &m, const KeyType &key) {

	

	return m.find(key) != m.end();

} 

void app() {
	map<string, int> stringInMap{ {"A", 1}, {"B", 2}, {"C", 3}};

	map<int, double> InDoubleMap{ {1,1.5}, {2,2.2}, {3,3.5}, {4,4.32} };

	printMap(stringInMap);
	printMap(InDoubleMap);

	cout << boolalpha;
	cout << containsKey(stringInMap, string("A")) << endl;

} */

template<typename KeyType, typename ValueType> 
class Dictionary {
	map<KeyType, ValueType> data;
public:
	void add(const KeyType &key, const ValueType &value) {
		data[key] = value;
	}

	ValueType get(const KeyType& key) const{
		auto it = data.find(key);
		if (it != data.end()) {
			return it->second;
		}
		else {
			cout << "Wrong Key" << endl;
		}
		/*if (data.find(key) != data.end() {
			return data[key];
		}
		else {
			cout << "Wrong Key" << endl;
		} */
	}

	bool containsKey(const KeyType& key) const {
		return data.find(key) != data.end();
	}

	void remove(const KeyType& key) {
		data.erase(key);
	}

	size_t getSize() const{
		return data.size();
	}

	void print() const{
		for (const auto& pair : data) {
			cout << pair.first << " , " << pair.second << endl;
		}
	}
};

void app() {
	Dictionary<string, int> ageDictionary;
	ageDictionary.add("A", 20);
	ageDictionary.add("B", 21);
	ageDictionary.add("C", 30);

	ageDictionary.print();

	cout << ageDictionary.get("A") << endl;

	cout << ageDictionary.getSize() << endl;
	
	ageDictionary.remove("A");

	ageDictionary.print();

	cout << boolalpha;
	cout << ageDictionary.containsKey("B") << endl;

}


int main() {
	//map_operations();

	app();

	return 0;
}