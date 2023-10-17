//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(vector<int> adj[],vector<int> &vis,int start,vector<int> &vec){
        if(vis[start] == 2)return true;
        if(vis[start] == 1)return false;
        vis[start] = 1;
        bool ans = true;
        for(auto itr : adj[start]){
            ans = ans and dfs(adj,vis,itr,vec);
        }
        if(ans == true){
            vec.push_back(start);
            vis[start] = 2;
        }
        return ans;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> ans;
        for(int i = 0;i < V;i++){
            if(adj[i].size() == 0){
                vis[i] = 2;
                ans.push_back(i);
            }
        }
        for(int i = 0;i < V;i++){
            if(vis[i] == 0){
                dfs(adj,vis,i,ans);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends