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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        queue<TreeNode*> que;

        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode* n1 = que.front();
            que.pop();

            TreeNode* n2 = que.front();
            que.pop();

            if (n1 == nullptr && n2 == nullptr)
                continue;

            if (n1 == nullptr || n2 == nullptr)
                return false;

            if (n1->val != n2->val)
                return false;

            que.push(n1->left);
            que.push(n2->right);

            que.push(n1->right);
            que.push(n2->left);
        }

        return true;
    }
};