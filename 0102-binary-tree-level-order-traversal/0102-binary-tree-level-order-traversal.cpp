/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 * 9    TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,ans);
        return ans;
    }
    private:
    void dfs(TreeNode* root,int level, vector<vector<int>> &ans){
        if(root == nullptr)
        return;
        if(level == ans.size())
        ans.emplace_back();
        ans[level].push_back(root->val);
        dfs(root->left,level + 1, ans);
        dfs(root->right,level + 1, ans);

    }
};