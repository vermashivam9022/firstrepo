#include<bits/stdc++.h>
using namespace std;
//kruksal - take min edge and add them into mst repeat until V-1 edges are included
/*
Add all edges into the priority queue, avoiding duplicates
Take first min edges from the priority queue and check it is includable in mst or not until V-1 edges are added or queue is empty
Find ultimate parent of u and v i.e par_u, par_v
if both ULTIMATE parents of u and v are not in same set then we can add into mst  i.e par_u!=par_v
for UnionnByRank
    1. find ultimate parent of u and v i.e par_u, par_v
    2. find the rank of ultimate parent i.e rank[par_u],rank[par_v]
    3. if rank[par_u] > rank[par_v] then make par_u as parent[par_v]
*/

// Findparent with path compression
int Findparent(int x, vector<int> &par)
{
    if(x==par[x])
        return x;
    par[x]= Findparent(par[x],par); // Path compression      recursive search for parent
    return par[x];
}

void UnionByRank(int u, int v, vector<int> &par, vector<int> &rank)
{
    int par_u = Findparent(u, par);
    int par_v = Findparent(v, par);

    if (rank[par_u] < rank[par_v])
        par[par_u] = par_v;
    else if (rank[par_u] > rank[par_v])
        par[par_v] = par_u;
    else {
        par[par_v] = par_u;
        rank[par_u]++;
    }
}

//Function to find sum of weights of edges of the Minimum Spanning Tree.
// Kruskal's Algorithm to find MST
int kruskal(int V, vector<vector<int>> adj[]) 
{
    vector<int> parent(V), rank(V, 0);

    for (int i = 0; i < V; i++) 
        parent[i] = i;             // Initialize each node as its own parent

    // Priority queue for sorting edges by weight
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Add edges to the priority queue, avoiding duplicates
    for (int i = 0; i < V; i++) {                         
        for (auto edge : adj[i]) {
            int u = i, v = edge[0], wt = edge[1];
            if (u < v) // To avoid duplicate edges
                pq.push({wt, {u, v}});
            
        }
    }

    int cost = 0; // Total cost of MST
    int edgesInMST = 0; // Track the number of edges in MST

    while (!pq.empty()) 
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        // Find parents of the vertices
        int par_u = Findparent(u, parent);
        int par_v = Findparent(v, parent);

        // If they are in different sets, include the edge in the MST
        if (par_u != par_v) {
            cost += wt;
            edgesInMST++;                   // Track the number of edges in MST TILL V-1
            UnionByRank(u, v, parent, rank);   // UPDATE Parent OF Ultimate Parent based on condition
        }
        if(edgesInMST == V - 1)    //if V-1 EDGES are imclude then break
            break;
    }

    return cost;
}

int main()
{
    //your code here
    int V = 4; 
    vector<vector<int>> adj[] = {
    {{1, 1}, {2, 4}},       // Edges from vertex 0: (0-1, weight 1), (0-2, weight 4)
    {{0, 1}, {2, 3}, {3, 2}}, // Edges from vertex 1: (1-0, weight 1), (1-2, weight 3), (1-3, weight 2)
    {{0, 4}, {1, 3}, {3, 2}}, // Edges from vertex 2: (2-0, weight 4), (2-1, weight 3), (2-3, weight 2)
    {{1, 2}, {2, 2}}         // Edges from vertex 3: (3-1, weight 2), (3-2, weight 2)
};

    cout<<"Minimum cost by kruskal is :"<< kruskal(V,adj)<<endl;

    vector<vector<int>> adj1[] = {
    {{1, 1}, {3, 4}},       // Edges from vertex 0: (0-1, weight 1), (0-3, weight 4)
    {{0, 1}, {2, 3}},       // Edges from vertex 1: (1-0, weight 1), (1-2, weight 3)
    {{1, 3}, {3, 2}, {4, 5}}, // Edges from vertex 2: (2-1, weight 3), (2-3, weight 2), (2-4, weight 5)
    {{0, 4}, {2, 2}, {4, 5}}, // Edges from vertex 3: (3-0, weight 4), (3-2, weight 2), (3-4, weight 5)
    {{2, 5}, {3, 5}}        // Edges from vertex 4: (4-2, weight 5), (4-3, weight 5)
};

    cout<<"Minimum cost by kruskal is :"<< kruskal(5,adj1)<<endl;


    return 0;
    
}

/*
   (0)
   / \
  1   4
 /   3  \
(1)-----(2)
  \     /
   2   2
    \ /
    (3)


    (0)---1---(1)
     |         |
     4         3
     |         |
    (3)---2---(2)
      \       /5
       \-5---(4)

       MST

     (0)---1---(1)
                |
                3
                |
    (3)---2---(2)
              / 
             / 5
           (4)


*/