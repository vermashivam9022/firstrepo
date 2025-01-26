#include<bits/stdc++.h>
using namespace std;

//prims Algorithm
/*
   start from any vertex then take min weight  of the adjeccent edge  of current mst which is not part of mst and include that minedge vertex
*/
int prims(int V,vector<vector<int>> adj[])
{
    vector<int> isMST(V,0);          // to check node is part of MST or not
    vector<int> parent(V,-1);        // it is useful to print the mst if printing not required then no need

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;   // wt, node ,parent

    
    pq.push({0,{0,-1}});    // Push the starting node with distance 0  //wt, node ,parent
    int minCost=0;

    while(!pq.empty())
    {
        int wt=pq.top().first;
        int u=pq.top().second.first;
        int par=pq.top().second.second;
        pq.pop();

        if(!isMST[u]) 
        {
            isMST[u]=1;       // mark is MST
            minCost+=wt;
            parent[u]=par;   // it is useful to print the mst if printing not required then no need

            for(auto n:adj[u])   // check for neighbors
            {
                int v=n[0];
                int weight=n[1];

                if(!isMST[v])                // check whether it is already part of mst or not, if not then consider
                    pq.push({weight, {v,u}});
            }
        }

    }

    return minCost;
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

  
    cout<<"Minimum cost by prims is :"<< prims(V,adj)<<endl;


vector<vector<int>> adj1[] = {
    {{1, 1}, {3, 4}},       // Edges from vertex 0: (0-1, weight 1), (0-3, weight 4)
    {{0, 1}, {2, 3}},       // Edges from vertex 1: (1-0, weight 1), (1-2, weight 3)
    {{1, 3}, {3, 2}, {4, 5}}, // Edges from vertex 2: (2-1, weight 3), (2-3, weight 2), (2-4, weight 5)
    {{0, 4}, {2, 2}, {4, 5}}, // Edges from vertex 3: (3-0, weight 4), (3-2, weight 2), (3-4, weight 5)
    {{2, 5}, {3, 5}}        // Edges from vertex 4: (4-2, weight 5), (4-3, weight 5)
};


    cout<<"Minimum cost by prims is :"<< prims(V,adj1)<<endl;

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