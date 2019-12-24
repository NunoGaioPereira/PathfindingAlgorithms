// Implementation of Dijkstra's shortest path algorithm.
#include <iostream>


#define V 9 // Number of vertices in graph

// Print the shortest path
void shortest_path(int dist[], int n)
{
   std::cout<<"Vertex "<<"\t\t"<<"Distance from Source\n";
   for (int i = 0; i < V; i++) {
      char c=65+i; // Print letter of node
      std::cout<<" \t\t \n"<< c<<" \t\t "<< dist[i];
   }
}

// Find the node with minimum distance to the source
int minDist(int dist[], bool visitedSet[])
{
   int min = INT_MAX, min_index;

   for (int i = 0; i < V; i++) {
      if (visitedSet[i] == false && dist[i] <= min) {
         min = dist[i];
         min_index = i; // Index of node with mininum distance
      }
   }
   return min_index;
}

// Calculate shortest paths from source to all other vertices
void Dijkstra(int weight[V][V], int src)
{
   int dist[V];
   bool visitedSet[V];

   for (int i = 0; i < V; i++) {
      dist[i] = INT_MAX; // Set distance of all nodes to infinity
      visitedSet[i] = false; // No node has been visited yet
   }

   dist[src] = 0; // Set distance of source node to source as zero

   for (int c = 0; c < V- 1; c++) {
      int u = minDist(dist, visitedSet); // Select node with shortest distance
      visitedSet[u] = true; // Set node as visited (true)

      for (int j = 0; j < V; j++) {
       if (!visitedSet[j] && weight[u][j] && dist[u]+ weight[u][j] < dist[j]) {
            dist[j] = dist[u] + weight[u][j]; // Update the distance to the minimum distance found
         }
      }
   }

   shortest_path(dist, V);
}

int main() {

      // Graph weights
      int G[V][V] = { 
      { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
      { 4, 0, 8, 0, 0, 0, 0, 9, 0 },
      { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
      { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
      { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
      { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
      { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
      { 8, 9, 0, 0, 0, 0, 1, 0, 7 },
      { 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

      Dijkstra(G, 0); // (weight graph, source node)

      return 0;
}