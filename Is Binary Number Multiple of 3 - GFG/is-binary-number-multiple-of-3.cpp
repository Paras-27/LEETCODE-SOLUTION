//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
        //complete the function here
         int num = 0;
        for(int i=0;i<s.length();++i){
            num = (num*2 + s[i])%3;
        }
        
        if(num%3 == 0) return 1;
        return 0;
    }

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends