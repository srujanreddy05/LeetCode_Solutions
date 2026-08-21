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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {

            if (curr->left != nullptr) {
                TreeNode* temp = curr->right;

                curr->right = curr->left;
                curr->left = nullptr;

                TreeNode* rightMost = getRightMost(curr->right);

                rightMost->right = temp;
            }

            curr = curr->right;
        }
    }

private:
    TreeNode* getRightMost(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }
};