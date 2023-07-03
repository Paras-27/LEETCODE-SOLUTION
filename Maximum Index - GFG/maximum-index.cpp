//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
         vector<int>right(n,0) ;
         
         for(int i=n-1;i>=0;i--) {
             
              right[i]=arr[i] ;
               if(i+1 <n)
              right[i]=max(right[i+1],arr[i]) ;
         }
         
         int j=0 ;
         int ans=0;
         for(int i=0;i<n;i++){
              
               while(j<n && right[j]>=arr[i]) {
                    j++;
               }
               ans=max(ans,j-i-1) ;
          }
          
          return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends