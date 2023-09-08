//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dis(N,1e8);
        vector<int> visited(N,0);
        queue<pair<int,int>> q;
        dis[src]=0;
        q.push({src,0});
        visited[src]=true;
        while(!q.empty()){
            int node=q.front().first;
            int score=q.front().second;
            q.pop();
            dis[node]=min(dis[node],score);
            for(auto i:adj[node]){
                if(!visited[i]){
                    q.push({i,score+1});
                    visited[i]=true;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]>=1e8){
                dis[i]=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends