#include<bits/stdc++.h>
using namespace std;

// Using Tarjans Algorithm Find strongly connected components
/*
1. DFS:
   - Perform DFS from all unvisited vertices.
   - Initilize the discovery and low times of vertices with current time.
   - Push the current vertex to the stack and mark the vertex in inStack present
   - If the neighbor is not visited then do DFS and update the low of current vertex.
   - If the neighbor is visited and inStack present (part of the current SCC) then update the low of current vertex.
   - If low and disc of current vertex is equal then empty the stack till current vertex and mark the vertex in inStack absent.
2. DFS  with 
*/
void dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &disc,vector<int> &low,vector<vector<int>> &res,stack<int> &s,vector<int> &inStack,int i,int &time)
{
    visited[i] = 1;
    disc[i] = low[i] = time++;
    s.push(i);
    inStack[i] = 1;

    for (int n: adj[i])
    {
        if (!visited[n])
        {
            dfs(adj, visited, disc, low, res, s, inStack, n, time);
            low[i] = min(low[i], low[n]);
        }
        else if (inStack[n])  // If the neighbor is in the stack (part of the current SCC)
        {
            low[i] = min(low[i], disc[n]);
        }
    }

    if (low[i] == disc[i])
    {
        vector<int> scc;
        while (s.top()!=i)
        {
            int u=s.top();
            scc.push_back(u);
            inStack[u] = 0;
            s.pop();
        }
        scc.push_back(i);
        inStack[i] = 0;
        s.pop();
        sort(scc.begin(),scc.end());
        res.push_back(scc);
    }
}

 vector<vector<int>> tarjans(int V, vector<vector<int>> &adj)
{
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> visited(V,0);
    vector<int> inStack(V,0);    // Tracks whether a node is in the stack
    stack<int> s;
    int time=0;
    vector<vector<int>> res;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, visited, disc, low, res, s, inStack, i, time);
        }
    }

    sort(res.begin(),res.end());      // to get in sorted
    return res;  // return strongly connected components in sorted order
    
}

void print(vector<vector<int>> &adj)
{
    for(int i=0;i<adj.size();i++)
    {
        for(int n:adj[i])
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //your code here
    int V = 5; 

    vector<vector<int>> adj= {
        {1},        // Node 0 -> Node 1
        {2},        // Node 1 -> Node 2
        {0, 3},     // Node 2 -> Node 0, Node 3
        {4},        // Node 3 -> Node 4
        {}          // Node 4 -> No edges
    };
    vector<vector<int>> res=tarjans(V,adj);
    cout<<"The SCC are:"<<endl;
    print(res);
    return 0;
}


/*

---------   
↓       ↑
0 → 1 → 2 
     ↓
     3 → 4
     
Strongly Connected Components:
{ 0 2 1 }
{ 3 }
{ 4 }

*/



