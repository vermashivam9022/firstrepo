#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int> > &adj,vector<bool> &visited,int start,int par)
{
    visited[start] = true;              // mark node as visited
    for(int neighbour :adj[start])
    {
        if(neighbour == par) continue;       // if neighbor is parents then ignore 
        if(visited[neighbour]) return true;  // if neighbor is NOT parents AND neighbor is also visited then cycle present
        if(dfs(adj, visited, neighbour, start)) return true;    // otherwise if not visited then go for recursion
    }                                                        //  if recursion found cycle then return true
    return false;               // in last if all node visited and not found cycle return false
}
bool bfs(vector<vector<int>> &adj,vector<bool> &visited,int start)
{
    vector<int> par(adj.size(),-1);
    queue<int> q;
    q.push(start);
   

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        visited[node] = true;
       
        for(auto i:adj[node])
        {
            if(i==par[node]) continue;
            if(visited[i]) return true;  // if neighbour is NOT parents AND neighbour is also visited then cycle present
            if(!visited[i])
            {
                q.push(i);
                visited[i] =true;
                par[i] = node;   // update parent of neighbour
            }
        }
    }
    return false;
}
bool iscycle(vector<vector<int>> &adj)
{
    int v=adj.size();
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++)          /// for All components check
        if (!visited[i] && dfs(adj,visited,i,-1))
            return true;

    return false;

}

int main()
{
    vector<vector<int>> adj = {
        {1, 3},    // Node 0 is connected to 1, 3
        {0, 2},    // Node 1 is connected to 0, 2
        {1, 3},    // Node 2 is connected to 1, 3
        {0, 2}     // Node 3 is connected to 0, 2
    };

    if(iscycle(adj))
        cout << "Graph 1 contains cycle" << endl;
    else
        cout << "Graph 1 does not contain cycle" << endl;

//************************************************************************************* */

    vector<vector<int>> adj2 = {
        {1, 2},  // Node 0 is connected to 1, 2
        {0},     // Node 1 is connected to 0
        {0}      // Node 2 is connected to 0
    };
    if(iscycle(adj2))
        cout << "Graph 2 contains cycle" << endl;
    else
        cout << "Graph 2 does not contain cycle" << endl;
    return 0;
}