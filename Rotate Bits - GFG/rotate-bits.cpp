//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            d=d-(d/16)*16;
            vector<int> ans;
                int l=d,n1=n;
                while(l){
                    if(n1 & (1<<15)){
                        n1=n1<<1;
                        n1=n1 ^ (1<<16);
                        n1++;
                    }else{
                        n1=n1<<1;
                    }
                    l--;
                }
                ans.push_back(n1);
                while(d){
                    if(n & 1){
                        n=n>>1;
                        n+=pow(2,15);
                    }else{
                        n=n>>1;
                    }
                    d--;
                }
                ans.push_back(n);
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends