//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isStraightHand(int N, int g, vector<int> &hand) 
    {
        map<int,int> mpp;
        
        for(int e:hand)
            mpp[e]++;
        
        if(N%g!=0)
            return false;
        
        while(mpp.size()>0)
        {
            int last=0;
            map<int,int>::iterator it=mpp.begin();  
            for(int i=0;i<g;i++)
            {
                pair<int,int> m=*it;
                
                if(i>0)
                {
                    if(last+1!=m.first)
                        return false;
                }
                
                last=m.first;
                mpp[m.first]--;
                if(mpp[m.first]==0)
                    mpp.erase(m.first);
                it++;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends