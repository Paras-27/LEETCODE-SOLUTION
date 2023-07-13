class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) {
            return {};
        }
        int n = mat[0].size();
        if (n == 0) {
            return {};
        }
        
        vector<int> ans(m * n);
        int k = 0;
        int i = 0, j = 0;
        int direction = 1; // 1: up-right, -1: down-left
        
        while (k < m * n) {
            ans[k++] = mat[i][j];
            
            if (direction == 1) { // Up-right
                if (j == n - 1) { // Reached last column
                    direction = -1;
                    i++;
                } else if (i == 0) { // Reached first row
                    direction = -1;
                    j++;
                } else { // Move diagonally up-right
                    i--;
                    j++;
                }
            } else { // Down-left
                if (i == m - 1) { // Reached last row
                    direction = 1;
                    j++;
                } else if (j == 0) { // Reached first column
                    direction = 1;
                    i++;
                } else { // Move diagonally down-left
                    i++;
                    j--;
                }
            }
        }
        
        return ans;
    }
};
