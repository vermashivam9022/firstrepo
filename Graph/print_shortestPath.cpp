#include<bits/stdc++.h>
using namespace std;

pair<vector<int>,int> print_shortestPath(vector<vector<pair<int, int>>> adj) {
    int n = adj.size();
    int start = 0;  // Starting node
    vector<int> dist(n, INT_MAX);  // Initialize distances to infinity
    vector<bool> visited(n, false);  // To keep track of visited nodes
    vector<int> parent(n);            // To Keep track Parent node
    dist[start] = 0;  // Distance to the start node is 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // Min-heap <distance, Node>
    pq.push({0, start});  // Push the starting node with distance 0
    parent[start] = -1;  // Initialize the parent of the start node as -1 (for backtracking)

    while (!pq.empty()) {
        int u = pq.top().second;  // Get the vertex with the smallest distance   (extract min distance)  O(logn)
        pq.pop();

        if (visited[u]) continue;  // Skip already visited nodes
        visited[u] = true;  // Mark this node as visited

        // Process all neighbors of u
        for (auto edge : adj[u]) {
            int adjNode = edge.first;           //neighbour node
            int edgeWeight = edge.second;     //edge weight

            // If a shorter path to v is found
            if (!visited[adjNode] && dist[u] + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dist[u] + edgeWeight;  // Update the distance
                pq.push({dist[adjNode], adjNode});  // Push the neighbor with the new distance
                parent[adjNode] = u;  // Update the parent of the neighbor as u (for backtracking)
            }
        }
    }
    // Print the shortest path and minimum distance

    vector<int> path;  // vector of paths to shortest distance 
    int last=n-1;
    while(last!=-1)
    {
        path.push_back(last);  // Add the vertex to the path
        last=parent[last];
    }
    reverse(path.begin(), path.end());  // Reverse the path to get the correct order

    int min_dist = dist[n-1];  // Get the minimum distance from the last node to the source node

    return {path,min_dist};  // Return the final distances
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

// Function to print the shortest path using Dijkstra's algorithm from node 0 to node n-1
    pair<vector<int>,int> dist=print_shortestPath(graph1);               // pair of shortest paths and distance
    vector<int> path=dist.first;

    // Display the path and distance clearly
    cout << "Path from Source 0 to Destination (n-1):" << endl;
    cout << "Source  ";
    
    for (int i = 0; i < path.size(); ++i) {
        // Print the path from the source to the destination   
        // for more readable and well-formatted manner 
        if (i == path.size() - 1) {                                       //for last elem NOT PRINT -> symbol
            cout << path[i];
        } else {
            cout << path[i] << " -> ";
        }
    }
    cout << endl;

    // Display the total distance
    cout << "Total Distance: " << dist.second << endl;


    return 0;
}