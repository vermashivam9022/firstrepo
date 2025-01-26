#include<bits/stdc++.h>
using namespace std;


void printListGraph(vector<vector<int>> graph)
{
    for (int i = 1; i <= graph.size()-1; i++)
    {
        cout << "Adjacency list of vertex " << i << ":";
        for (int x : graph[i])
            cout << " -> " << x;
        cout << "\n";
    }
    cout << "\n";
}
void printMatrixGraph(vector<vector<int>> graph)
{
    cout<<"Adjacency Matrix of Graph "<<endl;
    for (int i = 1; i <= graph.size()-1; i++)
    {
        cout << i << ":";
        for (int j = 1; j <= graph.size()-1; j++)
        {
            cout << "  " << graph[i][j];
        }
        cout << "\n";
    }
}

int main()
{
   
    int V,E;   // V- # of vertices, E is number of edges
    cout << "Enter the # of vertices and Edges: " << endl;
    cin >> V >> E ;

    // Adjecency List Representation : 

    vector<vector<int>> Graph(V+1);   // vertices are numbered from 1 to V  so we skip that 0 index

    // Adjecency Matrix Representation :

    vector<vector<int>> Graph1(V+1,vector<int>(V+1,0)); // vertices are numbered from 1 to V so
    for(int i=1; i<=E; i++)
    {
        int x,y;
        cin >> x >> y;

        //Adjeceny List store
        Graph[x].push_back(y);  //As if there is given edge 1-2   that means we have to store in both from 1-2 and 2-1
        Graph[y].push_back(x);

       // Adjecncy matrix STORE
        Graph1[x][y]=1;
        Graph1[y][x]=1;
    }
    printListGraph(Graph);
    printMatrixGraph(Graph1);


    return 0;
}

/*
Enter the # of vertices and Edges: 
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/