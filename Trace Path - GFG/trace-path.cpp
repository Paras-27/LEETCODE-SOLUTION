//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
    int minx=INT_MAX,miny=INT_MAX,maxx=INT_MIN,maxy=INT_MIN,x=0,y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L')y-=1;
            if(s[i]=='R')y+=1;
            if(s[i]=='D')x-=1;
            if(s[i]=='U')x+=1;
             minx=min(x,minx);
             maxx=max(maxx,x);
             miny=min(y,miny);
             maxy=max(y,maxy);
             if(abs(maxx-minx)>=n || (maxy-miny)>=m || abs(x)>=n || abs(y)>=m)return 0;
        }
       return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends