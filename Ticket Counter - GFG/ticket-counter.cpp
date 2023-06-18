//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int n, int k) {
        int a[]={1,n};
       bool f=0;
       while(a[1]-a[0]>k){
           if(f==0){
               a[0]+=k;
               f=1;
           }else{
               a[1]-=k;
               f=0;
           }
       }
      if(f==1)return a[0];
      return  a[1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends