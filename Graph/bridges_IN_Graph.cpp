#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>> &graph,vector<int> &visited,vector<int> &low,vector<int> &disc,vector<vector<int>> &bridges,int &time)
    {
        disc[node]=low[node]=time++;                            //intially discovery time and low value same
        visited[node]=1;                                        //make node as visited
        for(int neighbour:graph[node])
        {
            if(neighbour==parent)                              //if neighbor is parent then ignore
                continue;
            else if(!visited[neighbour])                       //if neighbor is not visited then
            {
                dfs(neighbour,node,graph,visited,low,disc,bridges,time);
                low[node]=min(low[node],low[neighbour]);

                if(low[neighbour]>disc[node])                      // to check bridge is present or not
                {
                    bridges.push_back({node,neighbour});
                }
            }
            else          // if neighbour is already visited that mean there is cycle  and not bridges present
            {
                low[node]=min(low[node],low[neighbour]);
            }
        }

    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i=0;i<connections.size();i++)     //edges are given in the form of connection so convert into Graph
        {
            int u=connections[i][0];
            int v=connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(n,0);    // visited array to keep track of nodes visited or not
        vector<int> low(n);         //This represents the earliest visited node that can be reached from a given node,
        vector<int> disc(n);          // discovery time
        vector<vector<int>> bridges;   // If Bridges are found, then push into this
        int time=1;                       // discovery time start from 1
        int node=0;                       //starting node          
        int parent=-1;


        dfs(node,parent,graph,visited,low,disc,bridges,time);

        return bridges;
    }
};


int main()
{
    //your code here
    int n = 4; 
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};      //connection is given in the following order
    Solution sol;
    vector<vector<int>> bridges=sol.criticalConnections(n,connections);

  

     // Displaying the Bridges
    for (const auto &bridges : bridges) {
        cout << "Bridges: " << bridges[0] << " , " << bridges[1] << endl;
    }
    return 0;
}

