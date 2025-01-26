#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[], vector<int> &visited, vector<int> &disc, vector<int> &low, vector<int> &result, int start, int par, int &time) {
    // Mark the current node as visited
    visited[start] = 1;

    // Initialize discovery time and low value for the current node
    low[start] = disc[start] = time++;
    
    // Count the number of children in the DFS tree (important for root node check)
    int children = 0; 

    // Traverse all adjacent vertices (neighbors) of the current node
    for (int neighbour : adj[start]) {
        // If the adjacent vertex is the parent of the current vertex in the DFS tree, skip it
        if (neighbour == par) 
            continue;

        // If the neighbor has not been visited, it's a tree edge
        if (!visited[neighbour]) {
            children++; // Increment the children count for the current node (only used for the root node check)

            //Recursively perform DFS on the unvisited neighbor
            dfs(adj, visited, disc, low, result, neighbour, start, time);

            // After the DFS call, update the low value of the current node based on its subtree
            low[start] = min(low[start], low[neighbour]);

            // Check if the current node is an articulation point (but not the root node)
            // An articulation point is found if there's no back edge from the subtree rooted at 'neighbour'
            if (par != -1 && low[neighbour]>=disc[start] ) {
                result[start] = 1; // Mark the current node as an articulation point
            }
        } 
        else {
            // If the neighbor is already visited and is not the parent, it's a back edge
            // Update the low value of the current node using the discovery time of the back edge
            low[start] = min(low[start], disc[neighbour]);
        }
    }

    // Special case for the root node:
    // If the current node is the root and has more than one child, it's an articulation point
    if (par == -1 && children > 1) {
        result[start] = 1; // Mark the root as an articulation point
    }
}

    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> visited(V,0);  //Keeps track of whether a node has been visited
        vector<int>disc(V,0);      //Stores the discovery time of a node (i.e., when the node is first visited).
        vector<int>low(V,0);       //Stores the lowest discovery time reachable from the node.
        vector<int>result(V,0);    //Stores whether a node is an articulation point (1 for articulation point, 0 otherwise).
        vector<int> artpoint;
        int start=0;
        int par=-1;
        int time=1;
        
        // Running DFS for each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj,visited,disc,low,result,start,par,time);
            }
        }

         // Collecting all articulation points
        for(int i=0; i<V;i++)                            // it give sorted order Articulation POint
        {
            if(result[i]==1)
                artpoint.push_back(i);
        }
        if(artpoint.empty())           // if there is no ARticulation POint retun -1
            return {-1};
        return artpoint;
    }


int main()
{
    int V = 5;
     // Representing the adjacency list as an array of arrays
    vector<int> adj[] = {
        {1},       // Node 0 points to Node 1
        {0, 2, 4}, // Node 1 points to Node 0, Node 2, and Node 4
        {1},       // Node 2 points to Node 1
        {4},       // Node 3 points to Node 4
        {1, 3},    // Node 4 points to Node 1 and Node 3
    };    

    // Example graph:
    // 0 -- 1 -- 2
    //      |
    // 3 -- 4
    
   
    vector<int> artPoints = articulationPoints(V, adj);
    
    if (artPoints.size() == 1 && artPoints[0] == -1)
        cout << "No articulation points" << endl;
    else
    {
        cout << "Articulation points are: ";
        for (int point : artPoints)
            cout << point << " ";
        cout << endl;
    }
    return 0;
}
