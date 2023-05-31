//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) 
    {
      unordered_map<int,int>temp;
      for(int i=0;i<n;i++)
      temp[arr[i]]++ ;
      unordered_map<int,int>::iterator it=temp.begin();
      int value=it->first, index=it->second;
      it++;
      while(it !=temp.end())
      {
          if(it->second<index)
          {
              index=it->second;
              value=it->first;
          }
          else if(it->second==index)
          {
              value=max(value,it->first);
          }
          it++ ;
      }
      
      return value ;
      
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends