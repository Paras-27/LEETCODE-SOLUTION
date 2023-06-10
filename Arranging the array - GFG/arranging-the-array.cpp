//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            queue<int> pos;
            queue<int> neg;
            
            for(int i = 0; i < n; i++){
                if(arr[i] >= 0){
                    pos.push(arr[i]);
                } else {
                    neg.push(arr[i]);
                }
            }
            
            int posSize = pos.size();
            int negSize = neg.size();
            int i = 0; 
            int j = negSize;
            
            while(posSize || negSize){
                if(negSize){
                    int negFront = neg.front();
                    neg.pop();
                    arr[i] = negFront;
                    i++;
                    negSize--;   
                }
                if(posSize){
                    int posFront = pos.front();
                    pos.pop();
                    arr[j] = posFront;
                    j++;
                    posSize--;
                }
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends