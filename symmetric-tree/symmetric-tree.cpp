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
    bool help(TreeNode* root,TreeNode* root1){
        if(root==NULL && root1==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(root1==NULL){
            return false;
        }
        int left=help(root->left,root1->right);
        int right=help(root->right,root1->left);
        if(left && right && root->val==root1->val){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return help(root->left,root->right);
    }
};