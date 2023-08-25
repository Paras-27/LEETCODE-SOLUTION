//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[],int i,vector<int> &visited){
        queue<pair<int,int>> q;
        q.push({i,-1});
        visited[i]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto ind:adj[node]){
                if(!visited[ind]){
                    q.push({ind,node});
                    visited[ind]=true;
                }
                else if(parent!=ind){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(bfs(adj,i,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends