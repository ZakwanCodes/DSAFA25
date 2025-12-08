#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

//graph: contains vertex/verticies and edge. Edge is the connection between 2 verticies 
//tree is a type of graph 
//adjecent matrix: # of rows and # of col = # of vertices in the graph 
// 4 verticies = 4 rows and 4 col
//if there's connected verticies between two vertex, we write 1 in the place of that matrix

void printGraph(vector<vector<int>> m) {
	for (size_t i = 0; i < m.size(); i++) {
		for (size_t j = 0; j < m[i].size(); j++ ) {
			cout << m[i][j] << " ";

		}
		cout << endl;
	}
}

void initMatrix(vector<vector<int>> &m, int v) {

	vector<int> temp_row = { 0,0,0,0,0,0 };

	for (int i = 0; i < v; i++) {
		m.push_back(temp_row);

	}
}

void adjacentMatrix(vector<vector<int>> m) {
	int v = m.size();
	vector<vector<int>> adjacentMat(v, vector<int>(v, 0)); int idx = 0;


	//initMatrix(adjacentMat, v);
	
	
	for (int i = 0; i < m.size(); i++) {
		int idx = 0;
		for (int j = 0; j < m[i].size(); j++) {
			idx = m[i][j];
			adjacentMat[i][idx] = 1;
			adjacentMat[idx][i] = 1;
		}
	}
	printGraph(adjacentMat); 
}

void DFS(vector<vector<int>> m) {
	int v = m.size();

	vector<bool> visited(v, false);

	stack<int> st;

	int start;

	cout << endl << endl << "Enter the starting vertex for DFS: ";
	cin >> start;
	
	if (start > v || start < 0) {
		return;
	}
	st.push(start);
	visited[start] = true;

	while (!st.empty()) {
		int u = st.top(); 
		st.pop();


		cout << "DFS: visiting vertex#: " << u << " ";
		cout << m[u].size() << endl;

		//how to access all neighbors of (all elements) of m[u]
		for (int x : m[u]) {
			cout << u << ": " << x << " ";
			if (!visited[x]) {
				visited[x] = true;
				st.push(x);
			}
			cout << endl;
		}
	}
}

void BFS(vector<vector<int>> m) {

	queue<int> q;

	cout << endl << endl << "Enter the starting vertex: " << endl;
	int start;
	cin >> start;
	int v = m.size();
	vector<bool> visited(v, false);

	if (start > v || start < 0) {
		return;
	}

	q.push(start);
	visited[start] = true;
	int u; //to store the first vertex sitting in the queue

	while (!q.empty()) {
		u = q.front();
		cout << "Visiting vertex#: " << u << endl;
		q.pop();
		cout << m[u].size() << endl;

		//how to access all neighbors of (all elements) of m[u]
		for (int x : m[u]) {
			cout << u << ": " << x << " ";
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
}




int main() {
	/*
	vector<vector<int>> matrix; 

	vector<int> row1 = { 1,1,1,0 };
	vector<int> row2 = { 1,0,1,1 };
	

	matrix.push_back(row1);
	matrix.push_back(row2);

	print(matrix);
	
	cout << "Chnage row1, col4" << endl;
	matrix[0][3] = 1;
	
	print(matrix);
	*/


	int v, e; //# of vertex and edge in our graph 

	cout << "Enter the number of vertices (v) and edges (e) in the graph" << endl;
	cin >> v >> e;
	cin.ignore();
	
	//create adjacency matrix
	//vector<vector<int>> graph(v);

	cout << "Enter " << e << " edges (v1,v2)" << endl;
	
	vector<vector<int>> mygraph;  vector<int> temp; int neighbor = 0;  string line;
	//code in question

	for (int i = 0; i < v; i++) {
		temp.clear();
		neighbor = 0;
		cout << "Enter neighbor of vertex# " << i << ": ";

		//cin.ignore();
		getline(cin, line);
		stringstream ss(line);

		while (ss >> neighbor) {
			if (neighbor == -1) break;
			temp.push_back(neighbor);
		}

		/*while (1) {
			cin >> neighbor;
			if (neighbor > v || neighbor < 0) {
				return -1;
			}
			if (neighbor == -1) {
				break;
			}
			temp.push_back(i);
		} */
		mygraph.push_back(temp);
	} 
	printGraph(mygraph);
	//adjacentMatrix(mygraph);

	//BFS(mygraph);
	DFS(mygraph);

	/*
	for (int j = 0; j < v; j++) {
		vector<int> temp;
		int neighborCount;

		cout << "Enter number of neighbors of vertex " << j << ": ";
		cin >> neighborCount;

		for (int k = 0; k < neighborCount; k++) {
			int neighbor;
			cout << "Enter neighbor " << k + 1 << " of vertex " << j << ": ";
			cin >> neighbor;

			if (neighbor < v && neighbor >= 0) {
				temp.push_back(neighbor);
			}
		}
		mygraph.push_back(temp);
	}
	printGraph(mygraph); 
	adjacentMatrix(mygraph, v, e); 
	*/

	//0 - 1, 0 2 4, 1 3, 2 4, 1 3 5, 4
	
	/*
	for (int i = 0; i < e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		//add v1 and v2 to graph[v1] and graph[v2]
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);

	}

	cout << "Graph Adjacency List" << endl;
	printGraph(graph); 
	adjacentMatrix(graph, v, e); */
	// wrong for (auto x : graph[v]) {
	//	cout << x << " ";
	//}
	/*
	cout << endl;   
	for (int i = 0; i < v; i++) {
		cout << i << ": ";
		for (int x : graph[i]) {
			cout << x << " ";
		}
		cout << endl;
	}  */


//	print(graph);


	return 0;
}