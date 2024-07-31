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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool miss = false;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front->left) {
                if (miss) return false;
                q.push(front->left);
            } else {
                miss = true;
            }

            if (front->right) {
                if (miss) return false;
                q.push(front->right);
            } else {
                miss = true;
            }
        }

        return true;
    }
};
