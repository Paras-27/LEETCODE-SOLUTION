class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int i ,int j){
        if(i<0 || j<0 || i>=grid.size()||j>=grid[0].size() || visited[i][j] ||grid[i][j]==0){
            return;
        }
        visited[i][j]=true;
        grid[i][j]=2;
        dfs(grid,visited,i+1,j);
        dfs(grid,visited,i,j+1);
        dfs(grid,visited,i,j-1);
        dfs(grid,visited,i-1,j);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        bool ch=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vector<vector<int>> visited(n,vector<int>(n,false));
                    dfs(grid,visited,i,j);
                    ch=true;
                    break;
                }
            }
            if(ch){
                break;
            }
        }
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1){
                    q.push({{i,j},{0}});
                }
            }
            // cout<<endl;
        }
        int v[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            pair<int,int> p=q.front().first;
            int x=p.first;
            int y=p.second;
            int len=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx=x+v[i][0];
                int newy=y+v[i][1];
                if(newx>=0 && newy>=0 && newx<n && newy<n && grid[newx][newy]!=1){
                    if(grid[newx][newy]==2){
                        return len;
                    }
                    q.push({{newx,newy},len+1});
                    grid[newx][newy]=1;
                }
            }
        }
    return 1;
    }
};