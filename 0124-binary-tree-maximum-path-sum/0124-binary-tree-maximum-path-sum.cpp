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
        int res = INT_MIN;

        function<int(TreeNode *)> inorder = [&](TreeNode * root){
            if(root!= nullptr){
                int left = max(0,inorder(root->left));
                int right = max(0,inorder(root->right));

                res = max(res, root->val + left +right);
                return root->val + max(left , right);
            }
            return 0;
        };

        inorder(root);

        return res;
    }
};