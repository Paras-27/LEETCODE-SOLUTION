//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int  dfs(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &visited,bool &check){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]!=1){
            return 0;
        }
        if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
            check=false;
        }
        visited[i][j]=1;
        int count = 1;
        count+=dfs(grid,i+1,j,visited,check);
        count+=dfs(grid,i-1,j,visited,check);
        count+=dfs(grid,i,j+1,visited,check);
        count+=dfs(grid,i,j-1,visited,check);
        return count;
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool check=true;
               if(!visited[i][j] && grid[i][j]==1){
                   int store=dfs(grid,i,j,visited,check);
                   if(check){
                       ans+=store;
                   }
               }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends