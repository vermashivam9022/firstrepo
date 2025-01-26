#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<int>> &adj, vector<int> &visited,int start,stack<int> &s)
{
    visited[start] = 1;               //mark visited to parent
    for(int neighbour:adj[start])
    {
        if(!visited[neighbour])      // first visit to all neighbours which are not visited and push them into stack
        {
            dfs(adj,visited,neighbour,s);
        }
    }
    s.push(start);              // after visiting all the neighbours push the parent node to stack
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int n=adj.size();
    vector<int> visited(n,0);          // visited array 
    stack<int> s;                    // stack is crucial for ensuring that nodes are processed in the correct order.

    for(int i=0;i<n;i++)    // to check for all node are visited are not
    {
        if(!visited[i])             // if not visites then call dfs
        {
            dfs(adj,visited,i,s);
        }
    }
    vector<int> res;
    while(!s.empty())                    // while stack is not empty push all nodes to res
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}



//Kahn's algorithm  for Topological  sort using bfs


vector<int> kahnTopologicalSort(vector<vector<int>> &adj)
{
    int n=adj.size();
    vector<int> indegree(n,0);
    vector<int> res;
    queue<int> q;
    for(int i=0;i<n;i++)                  //firsplacement preparation for cset find all nodes INdegrees
    {
        for(int neighbour:adj[i])
        {
            indegree[neighbour]++;
        }
    }
    for(int i=0;i<n;i++)                     //check the node which have indegree 0 push into queue
    {
        if(indegree[i]==0)
        {
            q.push(i);
            res.push_back(i);
        }
    }
    while(!q.empty())    // while the queue is not empty, pop out first node and decrement the indegree of  all neighbors
    {
        int node = q.front();
        q.pop();
        for(int neighbour:adj[node])
        {
            indegree[neighbour]--;
            if(indegree[neighbour]==0)         //if indegree of neighbor become 0 then push into queue
            {
                q.push(neighbour);
                res.push_back(neighbour);
            }
        }
    }
    if(res.size()!=n)                      // if res have less than  n value then graph has cycle
    {           // if there is cycle then node have indegree > 0 so there cant be push into queue, queue becomes empty 
        cout<<"Graph has a cycle";
        return {};
    }
    return res;
}


//************************************************************************************************
void printArray(const vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void print2DArray(const vector<vector<int> >&arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        cout << i << "->";
        printArray(arr[i]);
    }
}
//************************************************************************************************

int main()
{
    vector<vector<int>> adj = {
    {1}, // Node 0 points to 1
    {2}, // Node 1 points to 2
    {3}, // Node 2 points to 3
    {}   // Node 3 has no outgoing edges
    };
    print2DArray(adj);
    cout<<"Topological Sort: ";
    printArray(topologicalSort(adj));

    vector<vector<int>> adj2 = {
    {2},    // Node 0 points to 2
    {3},    // Node 1 points to 3
    {3},    // Node 2 points to 3
    {},     // Node 3 has no outgoing edges
    {0, 1}, // Node 4 points to 0 and 1
    {0, 2}  // Node 5 points to 0 and 2
    };

    cout << "********************************************" << endl;
    print2DArray(adj2);
    cout<<"Topological Sort: ";
    printArray(topologicalSort(adj2));

    cout << "********************************************" << endl;
    print2DArray(adj2);
    cout<<"Topological Sort: ";
    printArray(kahnTopologicalSort(adj2));

    return 0;
}







