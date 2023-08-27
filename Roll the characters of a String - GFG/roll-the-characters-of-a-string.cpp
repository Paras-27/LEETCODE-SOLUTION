//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string findRollOut(string s, long long arr[], int n)
	{
	    vector<int> v(n,0);
	    for(int i=0;i<n;i++){
	        v[arr[i]-1]++;
	    }
	    int store=0;
	    for(int i=n-1;i>=0;i--){
	        store+=v[i];
	        v[i]=store;
	    }
	    for(int i=0;i<n;i++){
            int ind=s[i]-'a';
	        ind+=v[i];
	        ind%=26;
	        char c='a'+ind;
	       // cout<<v[i]<<" "<<ind<<" ";
	        s[i]=c;
	    }
	   // char c='b'+6;
	   // cout<<c;
	    return s;
	}
};
	  


//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        string s;
        cin>>s;
        long long roll[n];
        for(int i=0;i<n;i++)
            cin>>roll[i];

       

        Solution ob;

        string res = ob.findRollOut(s, roll, n);
        cout << res;
		

        
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends