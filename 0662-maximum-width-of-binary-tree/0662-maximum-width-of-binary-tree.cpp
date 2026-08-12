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
    vector<long long> firstIndex;
    long long maxWidth = 0;

public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return (int)maxWidth;
    }

private:
    void dfs(TreeNode* root, int level, long long index) {
        if (root == nullptr)
            return;

        // First node at this level
        if (level == firstIndex.size()) {
            firstIndex.push_back(index);
        }

        // Normalize index
        long long currIndex = index - firstIndex[level];

        // Width of current level
        maxWidth = max(maxWidth, currIndex + 1);

        // Use normalized index for children
        dfs(root->left, level + 1, 2 * currIndex);
        dfs(root->right, level + 1, 2 * currIndex + 1);
    }
};