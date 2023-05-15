//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    long long countBits(long long N)
    {
        long long near = (1ll << (long long)log2(N));
        long long ans = (near / 2) * (long long)log2(N);
        if (__builtin_popcountll(N) == 1)
            return ans + 1;
        ans += (N - near + 1);
        ans += countBits(N - near);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends