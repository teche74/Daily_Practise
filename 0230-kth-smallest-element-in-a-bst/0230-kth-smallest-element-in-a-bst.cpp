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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;

        function<void(TreeNode *)>solve = [&](TreeNode *temp){
            if(temp != nullptr){
                solve(temp->left);
                res.emplace_back(temp->val);
                solve(temp->right);
            }
        };

        solve(root);
        for(auto t : res){
            cout<<t<<" ";
        }
        return res[k-1];
    }
};