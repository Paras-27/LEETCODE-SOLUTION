//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int row,col;
    public:
    
    bool isonedge(pair<int,int> p){
        int x=p.first,y=p.second;
        if(x==0 || x+1==row)return 1;
        if(y==0 || y+1==col)return 1;
        return 0;
    }
    
    bool checkifisland(vector<vector<int>>& matrix, int x, int y){
        if(x>=row || y>=col || x<0 || y<0)return 0;//out of boundary
        bool valid=1;
        int elem=matrix[x][y];
        matrix[x][y]=0;
        //if current cordinate is 1
        if(elem==1){
            //but it is on edge
            if(isonedge({x,y}))
            {
                //already invalid , but need to neutralise adjacent ones
                checkifisland(matrix,x,y+1);
                checkifisland(matrix,x+1,y);
                checkifisland(matrix,x-1,y);
                checkifisland(matrix,x,y-1);
                return 0;
            }
            else
            {valid=checkifisland(matrix,x,y+1)&checkifisland(matrix,x+1,y)&checkifisland(matrix,x-1,y)&checkifisland(matrix,x,y-1);}
        }
        //if(valid)cout<<x<<y<<endl;
        return valid;
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        row=N;
        col=M;
        // Code here
        int islands=0;
        for(int x=0;x<N;x++){
            for(int y=0;y<M;y++){
                int elem=matrix[x][y];
                if(elem==1){
                    if(checkifisland(matrix, x,y))
                    islands++;
                    //checksif valid island
                }
            }
        }
        return islands;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends