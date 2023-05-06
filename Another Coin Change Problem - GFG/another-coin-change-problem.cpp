//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    bool fun(int N, int K, int target, vector<int> &coins,vector<vector<int>> &dp){
        if(K<0 || target<0){
            return false;
        }
        if(dp[K][target]==1){
            return false;
        }
        if(K==0 and target==0){
            return true;
        }
        for(int i=0;i<N;i++){
            if(coins[i]<=target){
                if(fun(N,K-1,target-coins[i],coins,dp)){
                    return true;
                }
                
            }
        }
        dp[K][target]=1;
        return false;
    }
  
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<int>> dp(K+1,vector<int>(target+1,-1));
        for(int i=0;i<N;i++){
            if(coins[i]<=target){
                if(fun(N,K-1,target-coins[i],coins,dp)){
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
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends