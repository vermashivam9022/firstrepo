/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites 
where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include<bits/stdc++.h>
using namespace std;

bool isTopologocalSort(vector<vector<int>> &graph,int n,vector<int> &indegree,vector<int> &ans)          //using Kahns algorithm
    {
        queue<int> q;
        int count=0;                     // to count the number of node traversed in topological sort

        for(int i=0;i<n;i++)          // push those node whose indegree is zero
        {
            if(indegree[i]==0)
            {
                q.push(i);
                count++;
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            for(int x:graph[node])    // for all neighbors decrement indegree and check if indegree become 0 then enqueue into queue
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                    count++;
                }
            }
            ans.push_back(node);         // push the node into answer vector which will give the order of courses to be taken
        }

        if(count==n)            //indicate that all courses are finished
            return true;            // or we can return ans; else return { }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto x:prerequisites)                             //craeting graph
        {
            int a=x[0];
            int b=x[1];
            graph[b].push_back(a); 
            indegree[a]++;                                   // also increment indegree
        } 
        vector<int> ans;                         //answer vector which will give the order of courses to be taken
        return isTopologocalSort(graph,numCourses,indegree,ans);  // if topological sort for all node exist that means all can finished 
    }
int main()
{
    //your code here
    int numCourses = 2; 
    vector<vector<int>> prerequisites = {{1,0}};
    cout<<canFinish(numCourses,prerequisites)<<endl;

    return 0;
}