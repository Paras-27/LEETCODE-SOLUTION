/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isbst(TreeNode* root,long maxi,long mini){
        if(root==NULL){
            return true;
        }
        if(root->val <= mini || root->val>=maxi)
            return false;
        bool l=isbst(root->left,root->val,mini);
        bool r=isbst(root->right,maxi,root->val);
        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        return isbst(root,LONG_MAX,LONG_MIN);
    }
};