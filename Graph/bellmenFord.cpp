#include<bits/stdc++.h>
using namespace std;


// it works for negative edge weights but not works for negative weights cycles
vector<int> bellmanFord(int v,vector<vector<int>> &edges, int src)              //[[node1,node2,edges_wieght]]
{
    int e=edges.size();
    vector<int> dist(v,1e8);                              //1e9 = 10^8 INT_MAX
    dist[src]=0;
                                                             //here visite ARRAY not required
    for (int i = 0; i < v-1; i++)      // Do Relaxation for v-1 time for each edges
    {
        bool flag = false;
        for(int j = 0; j <e; j++)           // Relaxation for each edges
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int weight=edges[j][2];

            if(dist[u]==1e8)                 // to deal with (infinity - value) =infinity
                continue;
            if(dist[u]+weight<dist[v])
            {
                dist[v]=dist[u]+weight;
                flag=true;
            }     
        }
        if(!flag)         // if suppose after doing relaxation dist is not modified then it will be final dist
            return dist;
    }

// to detect cycle
    for(int j = 0; j <e; j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int weight=edges[j][2];

            if(dist[u]==1e8)                 // to deal with (infinity - value) =infinity
                continue;
            if(dist[u]+weight<dist[v])
                //cout<<"Graph contains negative weight cycle"<<endl;
                return {-1};
        }

    return dist;
    
}

int main()
{
    //your code here
    int v=5;
    vector<vector<int>> edges={{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 4, 5}};
    int src=0;
    vector<int> dist=bellmanFord(v,edges,src);
    for(int i=0; i<v; i++)
        cout<<"Distance of vertex "<<i<<" from source "<<src<<" is "<<dist[i]<<endl;

    return 0;
}