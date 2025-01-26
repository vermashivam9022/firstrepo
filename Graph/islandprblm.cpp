/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). 
Find the number of islands.
Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands 
horizontally or vertically or diagonally i.e., in all 8 directions.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0
 
There are two islands :- one is 1 1 1 and other is
                                  1 1                1
*/
#include<bits/stdc++.h>
using namespace std;
int r,c;
bool valid(int i,int j)
  {
      return (i>=0 && i <r && j>=0 && j<c);
  }
void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &visited)
{
    visited[i][j]=1;
    queue<pair<int,int>> q;
    
    q.push({i,j});
    
    while(!q.empty())
    {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        
        int r[8]={-1,1,0,0,-1,-1,1,1};
        int c[8]={0,0,-1,1,-1,1,-1,1};
        
        for(int k=0;k<8;k++)
        {
            if(valid(i+r[k],j+c[k]) && grid[i+r[k]][j+c[k]]!='0' && !visited[i+r[k]][j+c[k]] )
            {
                visited[i+r[k]][j+c[k]]=1;
                q.push({i+r[k],j+c[k]});
            }
        }
        
        
    }
}
// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    // Code here
    
    r=grid.size();
    c=grid[0].size();
    
    vector<vector<int>> visited(r,vector<int> (c,0));
    
    int island=0;
    
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    {
        if(!visited[i][j] && grid[i][j]!='0')
        {
            bfs(i,j,grid,visited);
            island++;
        }
        
    }
    
    return island;
}
int main()
{
    //your code here
    vector<vector<char>> grid={
        {'0','1','1','1','0','0','0'},
        {'0','0','1','1','0','1','0'}
    };

    cout<<"No of Island: "<<numIslands(grid)<<endl;
    return 0;
}