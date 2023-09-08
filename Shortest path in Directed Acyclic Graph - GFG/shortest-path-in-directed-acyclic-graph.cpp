//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<vector<pair<int,int>>> &adj,vector<int> & visited,int node,stack<int> &st){
        visited[node]=true;
        for(auto it:adj[node]){
            int i=it.first;
            if(!visited[i]){
                dfs(adj,visited,i,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> adj(N);
        vector<int> visited(N,false);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int> st;
        for(int i=0;i<N;i++){
            if(visited[i]==0){
                dfs(adj,visited,i,st);
            }
        }
        vector<int> dist(N,1e8);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it:adj[node]){
                int i=it.first;
                int cost=it.second;
                if(dist[node]+cost<dist[i]){
                    dist[i]=dist[node]+cost;
                }
            }
        }
        for(int i=0;i<N;i++){
            // cout<<dist[i]<<" ";
            if(dist[i]>=1e8){
                dist[i]=-1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends