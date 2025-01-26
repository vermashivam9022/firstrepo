#include<bits/stdc++.h>
using namespace std;

// Function to perform Depth First Search  o(v+2E)
void dfs_recursive(const vector<vector<int>> &graph,int node,unordered_set<int> & visited)
{
    visited.insert(node);
    cout<<node<<" ";

   for(int neighbour:graph[node])
   {
     if(visited.find(neighbour)==visited.end())    //if neighbour is not present in visited set then do this ..find give end address if not found
     {
        dfs_recursive(graph, neighbour, visited);
     }
   }

}

int main()
{
    // Adjacency list Representation of a Graph
     vector<vector<int>> graph = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 5},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {1},       // Neighbors of node 4
        {2}        // Neighbors of node 5
    };

    unordered_set<int> visited;
    cout << "Recursive DFS starting from node 0: ";
    dfs_recursive(graph, 0, visited);

// Recursive DFS deals with disconnected components 
    for (int i = 0; i < graph.size(); ++i) 
    {
        if (visited.find(i) == visited.end()) 
        {  // If node i has not been visited
            cout << "| "; // Separate components in output
            dfs_recursive(graph, i, visited);    // Start a DFS from this node
            
        }
    
    cout << endl;
    return 0;
    }
}