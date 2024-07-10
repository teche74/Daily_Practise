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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN ;

        function<int(TreeNode *)> solve = [&](TreeNode * root){
            if(root!= nullptr){
                int left = solve(root->left);
                int right = solve(root->right);
                int sum = root->val + max(0, left) + max(0, right);

                max_sum = max(max_sum , sum);

                return root->val + max(0, max(left, right));
            }
            return 0;
        };

        solve(root);
        return max_sum;
    }
};