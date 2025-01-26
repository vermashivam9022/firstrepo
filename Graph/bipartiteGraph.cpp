#include <bits/stdc++.h>
using namespace std;

bool Biapartite(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);  // Initialize all nodes as uncolored (-1)
    
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {  // Check each uncolored node (for disconnected graphs)
            color[i] = 0;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == -1) {  // If neighbor v is uncolored
                        color[v] = 1 - color[u];  // Color it opposite to u
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {  // If neighbor v has the same color as u
                        return false;  // Graph is not bipartite
                    }
                }
            }
        }
    }
    return true;  // Graph is bipartite if no conflicts found
}

int main() {
    vector<vector<int>> graph1 = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 3},     // Node 1 is connected to nodes 0 and 3
        {0, 3},     // Node 2 is connected to nodes 0 and 3
        {1, 2}      // Node 3 is connected to nodes 1 and 2
    };

    if (Biapartite(graph1))
        cout << "Graph 1 is Bi-partite." << endl;
    else
        cout << "Graph 1 is not Bi-partite." << endl;

    vector<vector<int>> graph2 = {
        {1, 2},    // Node 0 is connected to nodes 1 and 2
        {0, 2},    // Node 1 is connected to nodes 0 and 2
        {0, 1}     // Node 2 is connected to nodes 0 and 1
    };
    // Expected output: "Graph is not Bi-partite."

    if (Biapartite(graph2))
        cout << "Graph 2 is Bi-partite." << endl;
    else
        cout << "Graph 2 is not Bi-partite." << endl;

    return 0;
}
