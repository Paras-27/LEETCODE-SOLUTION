//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool cycle(vector<int> graph[],int node,vector<int> &visited,vector<int> & pathvisited){
        visited[node]=true;
        pathvisited[node]=true;
        for(auto i:graph[node]){
            if(!visited[i]){
                if(cycle(graph,i,visited,pathvisited)){
                    return true;
                }
            }
            else if(visited[i] && pathvisited[i]){
                return true;
            }
        }
        pathvisited[node]=false;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> graph[]) {
        vector<int> visited(n,0);
        vector<int> pathvisited(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!pathvisited[i]){
                if(!cycle(graph,i,visited,pathvisited)){
                    ans.push_back(i);
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