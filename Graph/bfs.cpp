#include<bits/stdc++.h>
using namespace std;


// tc: O(V+2E)
void bfs(const vector<vector<int> > &graph, int start,unordered_set<int> &visited)
{
    queue<int> q;
    q.push(start);
    visited.insert(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbour: graph[node])
        {
            if(visited.find(neighbour) == visited.end())
            {
                q.push(neighbour);
                visited.insert(neighbour);
            }
        }
    }
}
 
 //O(V+2E)   Instead of using set here uses visited Array
vector<int> bfs2(vector<vector<int>> graph,int start,int visited[])
{
    queue<int> q;
    q.push(start);
    vector<int> result;            // visiting order that will be return 

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = 1;
        result.push_back(node);
        for(auto i:graph[node])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return result;
}
void print_array(const vector<int> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}
  
int main()
{
     vector<vector<int>> graph = {
        {1, 2},    // Neighbors of node 0
        {0, 3, 4}, // Neighbors of node 1
        {0, 5},    // Neighbors of node 2
        {1},       // Neighbors of node 3
        {1},       // Neighbors of node 4
        {}        // Neighbors of node 5
    };
    int start = 5;    //Do bfs traversal from this node


    unordered_set<int> visited;   // make visited set to check whether elements are already visited or not
    bfs(graph, start,visited); // Start BFS from node 0


    // To deals with disconnected components 
    for (int i = 0; i < graph.size(); ++i) 
    {
        if (visited.find(i) == visited.end()) 
        {  // If node i has not been visited
            cout << "| "; // Separate components in output
            bfs(graph, i, visited);    // Start a BFS from this node
            
        }
    }   
    cout << endl;
//******************************************************************************* */
    // BFS from a different node

    int visited1[graph.size()]={0};
    vector<int> result = bfs2(graph, start,visited1);
    print_array(result); // Print the BFS traversal result from node 0
        // To deals with disconnected components 
    for (int i = 0; i < graph.size(); ++i) 
    {
        if (!visited1[i]) 
        {  // If node i has not been visited
            cout << "| "; // Separate components in output
            vector<int> result=bfs2(graph, i, visited1);    // Start a BFS from this node
            print_array(result); // Print
            
        }
    cout << endl;
    }   
   
    return 0;
}