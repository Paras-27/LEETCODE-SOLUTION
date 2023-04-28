//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void bfs(int n , int m, vector<vector<int>>&dis , vector<vector<char>>&c){
        queue<pair<int , int>>q ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(c[i][j] == 'W'){
                    q.push({i , j});
                    dis[i][j] = 0 ;
                }
            }
        }
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first , j = curr.second ;
            if(i - 1 >= 0 && dis[i-1][j] == -1 && c[i-1][j] != 'N'){
                dis[i-1][j] = dis[curr.first][curr.second] + 1 ;
                q.push({i - 1, j});
            }
            if(i + 1 < n && dis[i + 1][j] == -1 && c[i + 1][j] != 'N'){
                dis[i+1][j] = dis[curr.first][curr.second] + 1 ;
                q.push({i + 1 , j});
            }
            
            if(j - 1 >= 0 & dis[i][j-1] == -1 && c[i][j-1] != 'N'){
                dis[i][j-1] = dis[curr.first][curr.second] + 1 ;
                q.push({i , j -1});
            }
            if(j + 1 <= m && dis[i][j + 1] == -1 && c[i][j + 1] != 'N'){
                dis[i][j+ 1] = dis[curr.first][curr.second] + 1 ;
                q.push({i , j + 1});
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(c[i][j] == 'N' || c[i][j] == '.')dis[i][j] = 0 ;
                else if(dis[i][j] != -1)dis[i][j] *= 2 ;
                
            }
        }
        
    }
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>>distances(n , vector<int>(m , -1));
        bfs(n , m  , distances , c);
        
        return distances ;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends