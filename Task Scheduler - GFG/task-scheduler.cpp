//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &a) {
        // code here
        sort(a.begin(),a.end());
        int i,j=1,m=0,p=0;
        for(i=1;i<N;i++){
            // cout<<a[i]<<" ";
            if(a[i]==a[i-1]) {
                j++;
            }
            if(a[i]!=a[i-1]||i==N-1){
                if(j==m) p++;
                if(j>m){
                    m=j;
                    p=1;
                    j=1;
                }j=1;
            }
            // cout<<j<<" "<<p<<" ";
            // cout<<j<<" ";
        }
        return max(N,(K+1)*(m-1)+p);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends