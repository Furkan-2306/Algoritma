#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Graph {
private : 
	map<int, vector<int>>adjList;
public:
	void addVertex(int vertex) {
		if (adjList.find(vertex)==adjList.end()){
			vector <int>neighbors;
			adjList[vertex] = neighbors;
		}
	}
	void addEdge(int from, int to) {
		addVertex(from);
		addVertex(to);
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}
	void printGraph() {
		int numVertices = adjList.size();
		for (int i = 0; i < numVertices; i++) {
			int vertex = i;
			auto it = adjList.begin();
			advance(it,vertex);
			vector<int>& neighbors = adjList[it->first];
			cout << "adjcent to Vertex " << it->first << " : ";
			for (int j = 0; j < neighbors.size(); j++){
				cout << neighbors[j] << " ";
			}
			cout << endl;
		}
	}
	void removeVertex(int vertex) {
		if (adjList.find(vertex) != adjList.end()) {
			adjList.erase(vertex);
			for (map<int, vector<int>>::iterator it = adjList.begin(); it != adjList.end(); it++) {
				int key = it->first;
				vector<int>& neighbors = it->second;
				vector<int>::iterator vecIt = neighbors.begin();
				while (vecIt != neighbors.end()) {
					if (*vecIt == vertex) {
						vecIt = neighbors.erase(vecIt);
					}
					else {
						vecIt++;
					}
				}
			}
		}
	}
	void removeEdge(int from, int to) {
		if (adjList.find(from) != adjList.end() && adjList.find(to) != adjList.end()){
			vector<int>& fromNeighbors = adjList[from];
			vector<int>& toNeighbors = adjList[to];
			for (int i = 0; i < fromNeighbors.size(); i++) {
				if (fromNeighbors[i] == to) {
					fromNeighbors.erase(fromNeighbors.begin() + i);
					break;
				}
			}
			for (int i = 0; i < toNeighbors.size(); i++) {
				if (toNeighbors[i] == from) {
					toNeighbors.erase(toNeighbors.begin() + i);
					break;
				}
			}
		}
	 }
};

int main() {

	Graph g;

	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);

	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	cout << "Baslangic Graph:\n";
	g.printGraph();

	cout << endl;
	g.removeVertex(1);
	cout << "Vertex Silme Sonrasi Graph:\n";
	g.printGraph();

	g.removeEdge(2, 4);
	cout << "Edge Silme Sonrasi Graph:\n";
	g.printGraph();


	cout << endl << "Yeni Vertex ve edgeler ekleniyor...\n";
	g.addVertex(8);
	g.addEdge(2, 8);
	g.addEdge(8, 4);
	cout << "Yeni ekleme Sonrasi Graph:\n";
	g.printGraph();

	return 0;
}