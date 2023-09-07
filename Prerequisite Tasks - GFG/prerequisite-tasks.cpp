//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(n);
	    vector<int> indegree(n,0);
	    for(int i=0;i<p;i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        indegree[prerequisites[i].first]++;
	    }
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    int cnt=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        cnt++;
	        for(auto i:adj[node]){
	            indegree[i]--;
	            if(indegree[i]==0){
	                q.push(i);
	            }
	        }
	    }
	    return cnt==n;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends