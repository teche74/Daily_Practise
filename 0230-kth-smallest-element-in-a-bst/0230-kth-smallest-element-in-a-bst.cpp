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
    int count = 0,res = 0;
    int kthSmallest(TreeNode* root, int k) {

        function<void(TreeNode *)>solve = [&](TreeNode *temp){
            if(temp != nullptr){
                solve(temp->left);
                count++;
                if(count == k){
                    res = temp->val;
                    return;
                }
                solve(temp->right);
            }
        };

        solve(root);
        return res;

    }
};