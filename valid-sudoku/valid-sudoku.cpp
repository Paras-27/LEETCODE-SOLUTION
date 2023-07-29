class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int> hor(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.' )
                    continue;
                if(hor[board[i][j]-'0']){
                    return false;
                }
                hor[board[i][j]-'0']++;
            }
        }
        for(int i=0;i<9;i++){
            vector<int> ver(10,0);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.')
                    continue;
                if(ver[board[j][i]-'0']){
                    return false;
                }
                ver[board[j][i]-'0']++;
            }
        }
        cout<<1;
        int t=0;
        int x=0;
        int y=0;
        while(t<9){
            vector<int> box(10,0);
            for(int i=x;i<x+3;i++){
                for(int j=y;j<y+3;j++){
                    if(board[i][j]<'1' || board[i][j]>'9')
                        continue;
                    if(box[board[i][j]-'0'])
                        return false;
                    box[board[i][j]-'0']++;
                }
            }
            t++;
            x+=3;
            if(t%3==0){
                y+=3;
                x=0;
            }
        }
        return true;
    }
};