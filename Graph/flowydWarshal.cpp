#include <bits/stdc++.h>
using namespace std;


             
/*
//floydWarshall tc: o(v^3)   EC

if use dijkstra(ElogV or V^2) for V vertices then
for dense graph: V * V^2 =o(v^3)
for sparce graph: V * Elogv = o(V^2 log V)   as (E==V In sparse graph)


for Bellmanford algorithm(tc: VE)
for V vertices: V * VE = V* V V^2 =V^4    (in Worst case E == V^2 for complete graph)


*/
void floydWarshall(vector<vector<int>>& mat) {
    int n = mat.size();

    // Convert -1 (infinity) to INT_MAX for computation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == -1 && i != j)  // Keep 0 for diagonal, change -1 for non-diagonal to INT_MAX
                mat[i][j] = INT_MAX;
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

    // Convert INT_MAX back to -1 for unreachable paths
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == INT_MAX)
                mat[i][j] = -1;
        }
    }

    // Check for negative cycles by looking at diagonal elements
    for (int i = 0; i < n; i++) {
        if (mat[i][i] < 0) {
            cout << "Negative cycle detected.\n";
            return;
        }
    }
}

// Function to print the adjacency matrix
void printMatrix(vector<vector<int>> mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != -1)
                cout << mat[i][j] << " ";
            else
                cout << "INF ";
        }
        cout << endl;
    }
}

int main() {
    // Test case with a negative cycle
    vector<vector<int>> mat = {
    {0, -1, 2,4},  // From 0: 0->1 with weight 2, 0->2 with weight 5
    {3, 0, -1,10}, // From 1: 1->0 is -1 (no direct edge), 1->2 with weight 3
    {-1, -1, 0,1},
    {6,4,-1,0} // From 2: 2->0 is -1 (no direct edge), 2->1 is -1 (no direct edge)
};

    floydWarshall(mat);
    cout << "Floyd Warshall Matrix: " << endl;
    printMatrix(mat);

    return 0;
}


/*
void shortestDistance(vector<vector<int>>& mat) {
        int n=mat.size();
        for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
        {
            if(mat[i][k]!=-1 && mat[k][j]!=-1)                       // if i-k and k-j are not infinity then do
            {
                if(mat[i][j]==-1)                                          //if mat[i][j] is -1 then we have to max
                     mat[i][j] = max(mat[i][j], mat[i][k] + mat[k][j]);

                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
            
        }
} 

*/