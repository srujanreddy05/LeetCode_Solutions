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
    TreeNode* xParent = nullptr;
    TreeNode* yParent = nullptr;
    int xDepth = -1;
    int yDepth = -1;

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);
        return (xDepth == yDepth) && (xParent != yParent);
    }

private:
    void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (node == nullptr)
            return;

        if (node->val == x) {
            xParent = parent;
            xDepth = depth;
        }

        if (node->val == y) {
            yParent = parent;
            yDepth = depth;
        }

        dfs(node->left, node, depth + 1, x, y);
        dfs(node->right, node, depth + 1, x, y);
    }
};