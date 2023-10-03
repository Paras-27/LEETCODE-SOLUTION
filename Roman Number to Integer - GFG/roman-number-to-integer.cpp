//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map<char, int>mp={{'I', 1},{'V', 5}, {'X',10},{'L',50},{'C',100},{'D',500},{'M', 1000}};
        int ans=mp[str[str.size()-1]];
        for(int i=str.size()-2; i>=0; i--){
            int a=mp[str[i]], b=mp[str[i+1]];
            (b>a) ? ans-=a : ans+=a;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends