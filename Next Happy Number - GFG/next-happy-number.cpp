//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool happy(int i){
        while(i>=0 && i<=9){
            if(i==1 || i==7)//if it is 7 or 1 return true
                return true;
            else
                return false; 
        }
        int temp=i;
        int sum=0;
        while(temp){
            int rem=temp%10;
            sum+=(rem*rem);
            temp=temp/10;
        }
        return happy(sum);
    }
    int nextHappy(int N){
        // code here
        while(++N){
            if(happy(N))
                return N;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends