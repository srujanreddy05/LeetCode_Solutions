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
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
    private:
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(root->left == nullptr){
            return dfs(root->right) + 1;
        }
        if(root->right == nullptr){
            return dfs(root->left) + 1;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
       return  min(l,r) + 1;
    }
};