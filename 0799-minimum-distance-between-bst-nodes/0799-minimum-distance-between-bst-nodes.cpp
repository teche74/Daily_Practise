
class Solution {
public:
    void solve(TreeNode* root, int& prev, int& val) {
        if (root) {
            solve(root->left, prev, val);
            if (prev != -1) {
                val = min(val, root->val - prev);
            }
            prev = root->val;
            solve(root->right, prev, val);
        }
    }

    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int res = INT_MAX;
        solve(root, prev, res);
        return res;
    }
};
