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
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);

            if (reverse)
                node = node->right;   // Reverse inorder
            else
                node = node->left;    // Normal inorder
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (reverse)
            pushAll(node->left);
        else
            pushAll(node->right);

        return node->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {

        BSTIterator left(root, false);   // Smallest -> largest
        BSTIterator right(root, true);   // Largest -> smallest

        int i = left.next();
        int j = right.next();

        while (i < j) {

            if (i + j == k)
                return true;

            else if (i + j < k)
                i = left.next();

            else
                j = right.next();
        }

        return false;
    }
};