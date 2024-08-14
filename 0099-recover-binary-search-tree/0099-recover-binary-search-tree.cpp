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
    void solve(TreeNode * root, TreeNode * & first, TreeNode * & second , TreeNode * & prev){
        if(root){
            solve(root->left,first , second, prev);
            if(prev != nullptr && root->val < prev->val){
                if(!first){
                    first = prev;
                }
                second = root;
            }
            prev =root;
            solve(root->right, first,second, prev);
        }
    }
    void recoverTree(TreeNode* root) {
        TreeNode * first = nullptr, * second = nullptr, * prev = nullptr;

        solve(root,first, second,prev);

        swap(first->val, second->val);
    }
};