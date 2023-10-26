//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
     int n= A.length();
        int dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0; j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=0; i<n; i++)
          dp[i][i]=1;
        for(int i=n-1; i>-1; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(A[i]==A[j])
                {
                    if(i==j-1)
                    {
                        dp[i][j]=2;
                    }
                    else dp[i][j]=2+dp[i+1][j-1];
                }
                else
                 dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
    int minimumNumberOfDeletions(string S) { 
        return S.size()-longestPalinSubseq(S);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends