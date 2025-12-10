#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<vector<int>> convertToList(vector<vector<int>> matrix) {
	vector<vector<int>> list(matrix.size());

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 1) {
				list[i].push_back(j);
			}
		}
	}

	return list;
}


int main() {

	vector<vector<int>> Matrix =
	{
		{0, 1, 1, 0},
		{1, 0, 0 , 0},
		{1, 0, 0, 0}

	};

	vector<vector<int>> list = convertToList(Matrix);

	for (int i = 0; i < list.size(); i++) {
		cout << i << " : ";
		for (int j = 0; j < list[i].size(); j++) {
			cout << list[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}




/*
class graph {
private:
	vector<vector<int>> adjList;
	vector<vector<int>> adjMatrix;
public:
	graph(int size) {
		for (int i = 0; i < size; i++) {
			adjList.push_back({});
		}
	}

	void addVerticies(int a, int b) {
		adjList[a].push_back(b);
		adjList[b].push_back(a);

	}

	void printGraph() {
		for (int i = 0; i < adjList.size(); i++) {
			cout << i << " : ";
			for (int j = 0; j < adjList[i].size(); j++) {
				cout << adjList[i][j] << " ";
			}
			cout << endl;
		}
	}

	void convertListToMatrix() {

		adjMatrix.resize(adjList.size(), vector<int>(adjList.size(), 0));
		for (int i = 0; i < adjList.size(); i++) {
			for (int j = 0; j < adjList[i].size(); j++) {
				int idx = adjList[i][j];
				adjMatrix[i][idx] = 1;
				adjMatrix[idx][i] = 1;
			}
		}
	}

	void printAdjMatrix() {
		for (int i = 0; i < adjMatrix.size(); i++) {
			for (int j = 0; j < adjMatrix.size(); j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}


	void DFS(int start) {


		vector<bool> visited(adjList.size(), false);
		

		stack<int> st;
		st.push(start);
		visited[start] = true;

		while (!st.empty()) {
			int temp = st.top();
			cout << temp << " ";
			st.pop();
			
			for (int x : adjList[temp]) {
				if (!visited[x]) {
					visited[x] = true;
					st.push(x);
				}
			}
		}





	}


};




int main() {


	graph myGraph(6);
	myGraph.addVerticies(1, 2);
	myGraph.addVerticies(2, 3);
	myGraph.addVerticies(1, 3);
	myGraph.addVerticies(3, 4);

	myGraph.printGraph();
	myGraph.convertListToMatrix();
	myGraph.printAdjMatrix();

	myGraph.DFS(4);

	return 0;
} */