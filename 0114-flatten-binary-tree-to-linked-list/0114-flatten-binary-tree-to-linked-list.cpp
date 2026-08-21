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
    vector<TreeNode*> ans;

public:
    void flatten(TreeNode* root) {
        preorder(root);

        for (int i = 0; i + 1 < ans.size(); i++) {
            ans[i]->left = nullptr;
            ans[i]->right = ans[i + 1];
        }

        if (!ans.empty()) {
            ans.back()->left = nullptr;
            ans.back()->right = nullptr;
        }
    }

    void preorder(TreeNode* root) {
        if (root == nullptr)
            return;

        ans.push_back(root);

        preorder(root->left);
        preorder(root->right);
    }
};