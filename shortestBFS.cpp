// Breadth First Search to find the shortest path from a source node to a destination
// This implementation uses std::list to represent the adjacency matrix that contains the edges of the graph

#include <iostream>
#include <list>


class Graph {
	private:
		int V; // number of vertices
		std::list <int> *adj; // adjacency list to store the edges

	public:
		Graph(int v);
		void addEdge(int v, int w);
		void BFS(int s); 
		bool shortestBFS(int s, int t);
};

Graph::Graph(int v) {
	V = v;
	adj = new std::list<int>[v];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];

	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}

	std::list<int> queue; // queue for bfs
	queue.push_back(s); // put source node in the queue
	visited[s] = true; // mark node as visited

	//  while queue is not empty
	while(!queue.empty()) {
		
		s = queue.front(); // get front of the queue
		queue.pop_front(); // remove front of the queue

		// Get all adjacent vertices 
		std::cout << "Checking adjacent vertices for vertex " << s << std::endl;
		for(std::list<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true; // mark node as visited
				queue.push_back(*it); // add node to queue to check it's neighbour
			}
		}

	}

}

bool Graph::shortestBFS(int s, int t) {
	bool visited[V]; // list of visited nodes
	int dist[V]; // distance array
	int pred[V]; // predecessor


	for (int i = 0; i < V; i++) { 
        visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
    } 

	std::list<int> queue; // queue for bfs
	queue.push_back(s); // add source to the queue
	visited[s] = true; // origin node is visited
	dist[s] = 0;

	// While queue is not empty
	while(!queue.empty()) {
		
		s = queue.front(); // get front of the queue
		queue.pop_front(); // remove front of the queue

		// Get all adjacent vertices 
		std::cout << "Checking adjacent vertices for vertex " << s << std::endl;
		for(std::list<int>::iterator it = adj[s].begin(); it != adj[s].end(); it++) {
			if(!visited[*it]) {
				std::cout << "Node: " << *it << std::endl;
				visited[*it] = true; // mark node as visited
				dist[*it] = dist[s] + 1; // increase distance
				pred[*it] = s;

				queue.push_back(*it); // add node to queue to check it's neighbour

				if (*it == t) { // stop search if have reached the destination and print shortest path
					std::vector<int> path; // will contain the shortest path
				
					int temp = t; 
					path.push_back(temp);

					while(pred[temp] != -1) {
						path.push_back(pred[temp]); 
						temp = pred[temp];
					}

					// Distance from source is in distance array 
				    std::cout << "Shortest path length is : " << dist[t]; 
				  
				    // Printing path from source to destination 
				    std::cout << "\nPath is: "; 
				    for (int i = path.size() - 1; i >= 0; i--) {
				        std::cout << path[i] << " "; 
				    }


                	return true; 
                }
			}
		}

	}
	return false;
}

int main() {

	// Create graph with 6 nodes		
	Graph g(6);

	// Add edges
	g.addEdge(0,1);
	g.addEdge(0,2);

	g.addEdge(1,0);
	g.addEdge(1,3);
	g.addEdge(1,4);

	g.addEdge(2,0);
	g.addEdge(2,4);

	g.addEdge(3,1);
	g.addEdge(3,4);
	g.addEdge(3,5);

	g.addEdge(4,1);
	g.addEdge(4,2);
	g.addEdge(4,3);
	g.addEdge(4,5);

	g.addEdge(5,3);
	g.addEdge(5,4);

	g.shortestBFS(2,1);


	return 0;
}