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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;

        que.push(p);
        que.push(q);

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
            que.push(n2->left);

            que.push(n1->right);
            que.push(n2->right);
        }

        return true;
    }
};