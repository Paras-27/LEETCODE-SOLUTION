//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long MOD=1000000007;
  
  vector<vector<long long> > power(vector<vector<long long> > a, long long N){
      if(N==1){
          return a;
      }
      vector<vector<long long> > b=power(a,N/2);
      vector<vector<long long> > c(2,vector<long long>(2,0));
      c[0][0]=(b[0][0]*b[0][0]+b[0][1]*b[1][0])%MOD;
      c[0][1]=(b[0][0]*b[0][1]+b[0][1]*b[1][1])%MOD;
      c[1][0]=(b[1][0]*b[0][0]+b[1][1]*b[1][0])%MOD;
      c[1][1]=(b[1][0]*b[0][1]+b[1][1]*b[1][1])%MOD;
      if(N%2==0){
          return c;
      }
      b[0][0]=(a[0][0]*c[0][0]+a[0][1]*c[1][0])%MOD;
      b[0][1]=(a[0][0]*c[0][1]+a[0][1]*c[1][1])%MOD;
      b[1][0]=(a[1][0]*c[0][0]+a[1][1]*c[1][0])%MOD;
      b[1][1]=(a[1][0]*c[0][1]+a[1][1]*c[1][1])%MOD;
      return b;
  }
    int countStrings(long long int N) {
        // Code here
        long long x=1, y=1;
        vector<vector<long long> > a={{1,1},{1,0}};
        a=power(a,N+1);
        return a[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends