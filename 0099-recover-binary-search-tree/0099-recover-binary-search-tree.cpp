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
    void recoverTree(TreeNode* root) {
        TreeNode * prev = nullptr , *first = nullptr, *second = nullptr;

        function<void(TreeNode* , TreeNode * &)> solve = [&](TreeNode * curr, TreeNode* & prev){
            if(curr){
                solve(curr->left , prev);
                if(prev && prev->val > curr->val){
                    if(!first){
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                solve(curr->right , prev);
            }
        };


        solve(root , prev);
        swap(first->val,second->val);
    }
};