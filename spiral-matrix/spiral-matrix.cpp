class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=0;
        int level=0;
        set<pair<int,int>> s;
        bool ch=true;
        while(m>0 && n>0){
            // cout<<i<<" "<<j<<" ";
            for(;j<m;j++){
                if(!s.count({i,j}))
                    v.push_back(matrix[i][j]);
                else{
                    ch=false;
                    break;
                }
                s.insert({i,j});
            }
            if(!ch){
                break;
            }
            j--;
            i++;
            // cout<<i<<" "<<j<<" ";
            for(;i<n;i++){
                if(!s.count({i,j}))
                    v.push_back(matrix[i][j]);
                else{
                    ch=false;
                    break;
                }
                s.insert({i,j});
            }
            if(!ch){
                break;
            }
            i--;
            j--;
            // cout<<i<<" "<<j<<" ";
            for(;j>=level;j--){
                if(!s.count({i,j}))
                    v.push_back(matrix[i][j]);
                else{
                    ch=false;
                    break;
                }
                s.insert({i,j});
            }
            if(!ch){
                break;
            }
            j++;
            i--;
            // cout<<i<<" "<<j<<" ";
            for(;i>level;i--){
                if(!s.count({i,j}))
                    v.push_back(matrix[i][j]);
                else{
                    ch=false;
                    break;
                }
                s.insert({i,j});
            }
            if(!ch){
                break;
            }
            i++;
            j++;
            // cout<<i<<" "<<j<<" ";
            // cout<<"\n";
            m--;
            level++;
            n--;
        }
        return v;
    }
};