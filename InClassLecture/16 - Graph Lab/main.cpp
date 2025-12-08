#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class PrivateGraph {
private:
	int n; // number of vertices
	vector<vector<int>> adj; // adjacency list

public:
	// Constructor: create a graph with n vertices
	PrivateGraph(int numVertices) {
		n = numVertices;
		for (int i = 0; i < n; i++) {
			adj.push_back({});
		}
	}

	// Add an undirected edge between u and v
	void addEdge(int u, int v) {
		if ((u < 0 || u >= n) || (v < 0 || v >= n)) {
			return;
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// Print the adjacency list (for debugging)
	void printGraph() const {
		for (int i = 0; i < n; i++) {
			cout << i << ": ";
			for (int j = 0; j < adj[i].size(); j++) {
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
	}

	// Perform BFS starting from 'start' and print the BFS order
	void bfs(int start) const {
		queue<int> q;
		vector<bool> visited(n, false);

		if (start >= n || start < 0) return;

		q.push(start);
		visited[start] = true;


		while (!q.empty()) {
			int temp = q.front();
			cout << "Visting vertex#: " << temp << endl;
			q.pop();
			
			for (int x : adj[temp]) {
				if (!visited[x]) {
					visited[x] = true;
					q.push(x);
				}
			}

		}

	}

	// Perform BFS and fill dist[i] with distance from 'start' to i

	void bfsWithDistance(int start, vector<int>& dist) const {
		dist.clear();
		for (int i = 0; i < n; i++) {
			dist.push_back(-1);
		}

		if (start < 0 || start >= n) {
			cout << "Invalid start vertex" << endl;
			return;
		}

		vector<bool> visited(n, false);
		queue<int> q;

		visited[start] = true;
		dist[start] = 0;
		q.push(start);

		while (!q.empty()) {
			int temp = q.front();
			q.pop();
			for (int x : adj[temp]) {
				if (!visited[x]) {
					visited[x] = true;
					dist[x] = dist[temp] + 1;   
					q.push(x);
				}
			}
		}
	}


	// Return true if there is a path from 'start' to 'target'
	bool hasPath(int start, int target) const {
		queue<int> q;
		vector<bool> visited(n, false);

		if ((start >= n || start < 0) || (target >= n || target < 0)) {
			cout << "Starting vertex or target vertex is not in the graph" << endl;
			return false;
		}

		q.push(start);
		visited[start] = true;


		while (!q.empty()) {
			int temp = q.front();
			q.pop();

			if (temp == target) {
				cout << "The graph has a path between: " << start << " and " << target << endl;
				return true;
			}

			for (int x : adj[temp]) {
				if (!visited[x]) {
					visited[x] = true;
					q.push(x);
				}
			}

		}
		
		cout << "The graph does NOT have a path between: " << start << " and " << target << endl;
		return false;

	}
};

int main() {

	PrivateGraph mygraph(10);
	mygraph.addEdge(0, 1);
	mygraph.addEdge(1, 2);
	mygraph.addEdge(1, 3);
	mygraph.addEdge(1, 4);
	mygraph.addEdge(2, 3);
	mygraph.addEdge(2, 5);
	mygraph.addEdge(5, 6);
	mygraph.addEdge(6, 7);
	mygraph.addEdge(7, 8);
	mygraph.addEdge(8, 9);


	mygraph.printGraph();

	mygraph.bfs(0);
	mygraph.hasPath(0,9);

	vector<int> v;	
	mygraph.bfsWithDistance(2, v);

	for (int i = 0; i < v.size(); i++) {
		cout << "Distance from 2 to " << i << " is " << v[i] << endl;
	}



	return 0;
}