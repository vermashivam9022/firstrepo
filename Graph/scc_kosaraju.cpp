#include<bits/stdc++.h>
using namespace std;

//using kosaRaju Algorithms
// in directed garph, scc is subset of vertice where every vertex in that subset is reachable from every other vertex in  same subset by traversing the direct edges
/*
1. find topological sort using dfs (not kahns algorithm) it might give wrong bcos topological sort only possible for DAG
   but we don't have to bother about this we need only the topological order for scc1 -> scc2 ->scc3 like this order
                                    OR

   Perform a DFS on the original graph to compute the finishing order of nodes i.e topological sort.


2. then reverse the edge of the graph      // we r reversing the edge to go correct order from 1 scc to another scc
3. pop the elements from stack which was push while the find  topological order
       if is it not visited then
        a) mark it as visited and scc++
        b) dfs on its neighbours

time complexity : O(V+E)
space complexity : O(V+E
*/

//Find topological order or compute the finishing order of nodes
void topologicalSort(int i,vector<vector<int>>& adj,vector<int> &visited, stack<int> &s)
{
    visited[i]=1;
    
    for(int n:adj[i])
    {
        if(!visited[n])
        {
            topologicalSort(n,adj,visited,s);
        }
    }
    
    s.push(i);
}

//simple dfs algorithm

void dfs(int i,vector<vector<int>>& adj2,vector<int> &visited2)
{
    visited2[i]=1;
    
    for(int n:adj2[i])
    {
        if(!visited2[n])
        {
            dfs(n,adj2,visited2);
        }
    }
}

//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>>& adj)
{
    //code here
    
    stack<int> s;             // to store topological order        
    vector<int> visited(V,0);
    
    // find topological order
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            topologicalSort(i,adj,visited,s);
        }
    }
    
    //reverse the edges of the graph

    vector<vector<int>> adj2(V);
    
    for(int i=0;i<V;i++)
    {
        for(int n:adj[i])
        {
            int u=i;
            int v=n;
            
            adj2[v].push_back(u);
        }
    }
    
    
    int scc=0;
    vector<int> visited2(V,0);
    
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        
        if(!visited2[node])
        {
            dfs(node,adj2,visited2);
            scc++;
        }
        
    }
    
    return scc;
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
    cout<<"No of SCC are:"<<kosaraju(V,adj)<<endl;
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



