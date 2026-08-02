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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
       height(root);
       return diameter; 
    }
    private:
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        diameter = max(diameter,l + r);
        return max(l , r ) + 1;

    }
};