//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool cycle(vector<int> &visited,vector<int> & pvisited,vector<int> adj[],int i){
        visited[i]=true;
        pvisited[i]=true;
        bool ans=false;
        for(auto node:adj[i]){
            if(pvisited[node]==0 && visited[node]==0){
                ans |=cycle(visited,pvisited,adj,node);
            }
            else if(pvisited[node]){
                return true;
            }
        }
        pvisited[i]=0;
        return ans;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        vector<int> visited(n,0);
        vector<int> pvisited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(cycle(visited,pvisited,adj,i)){
                    return true;
                }
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends