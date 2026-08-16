/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root, TreeNode* par) {
        if (root == nullptr)
            return;

        parent[root] = par;

        buildParent(root->left, root);
        buildParent(root->right, root);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Step 1: Build parent mapping
        buildParent(root, nullptr);

        // Step 2: BFS from target
        queue<TreeNode*> q;

        // We need a SET, not a map
        unordered_set<TreeNode*> visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while (!q.empty()) {

            // Once we reach distance k, stop
            if (dist == k)
                break;

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                // Move left
                if (curr->left &&
                    visited.insert(curr->left).second) {
                    q.push(curr->left);
                }

                // Move right
                if (curr->right &&
                    visited.insert(curr->right).second) {
                    q.push(curr->right);
                }

                // Move to parent
                if (parent[curr] &&
                    visited.insert(parent[curr]).second) {
                    q.push(parent[curr]);
                }
            }

            dist++;
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};