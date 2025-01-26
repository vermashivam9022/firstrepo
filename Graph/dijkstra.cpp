#include<bits/stdc++.h>
using namespace std;

/*
TC:  for priority queue push/pop take logE time and there are max E edges can push/pop
ElogE+ELogE=  O(ElogE)  => O(Elogv^2) => 2ElogV =>(Elogv)
push/pop                     E=O(V^2)


TC: ElogV
SC: O(V+E)  { V- DIST, E- IN priority queue max E edges can be enter}
*/
vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int start) {      //[0: [{edge, weight},{edge, weight}]]
    int n = adj.size();
    vector<int> dist(n, INT_MAX);  // Initialize distances to infinity
    dist[start] = 0;  // Distance to the start node is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min-heap <distance, Node>
    pq.push({0, start});  // Push the starting node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the smallest distance   (extract min distance)  O(logn)
        pq.pop();

        // Process all neighbors of u
        for (auto edge : adj[u]) {
            int adjNode = edge.first;           //neighbour node
            int edgeWeight = edge.second;     //edge weight

            // If a shorter path to v is found
            if (dist[u] + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dist[u] + edgeWeight;  // Update the distance
                pq.push({dist[adjNode], adjNode});  // Push the neighbor with the new distance
            }
        }
    }

    return dist;  // Return the final distances
}

int main()
{
    vector<vector<pair<int, int>>> graph1 = {
    {{1, 10}, {3, 5}},     // Vertex 0: (1, 10) and (3, 5)             {edge,weight}
    {{2, 1}, {3, 2}},      // Vertex 1: (2, 1) and (3, 2)
    {{4, 4}},              // Vertex 2: (4, 4)
    {{1, 3}, {2, 9}, {4, 2}},  // Vertex 3: (1, 3), (2, 9), (4, 2)
    {{0, 7}, {2, 6}}       // Vertex 4: (0, 7) and (2, 6)
    };

// Function to find the shortest path using Dijkstra's algorithm
    vector<int> dist=dijkstra(graph1,0);                                 // distance vector from node 0
    cout << "Vertex Distance from Source 0:" << endl;
    for (int i = 0; i < dist.size(); ++i)
        cout << "To " << i << " : " << dist[i] << endl;

    return 0;
}