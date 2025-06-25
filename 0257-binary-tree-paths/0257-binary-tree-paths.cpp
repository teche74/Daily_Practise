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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string temp = "";


        function<void(TreeNode *)> solve = [&](TreeNode * root){
            if(root){
                string t = temp;
                temp += to_string(root->val);
                if(!root->left && !root->right){
                    res.push_back(temp);
                    temp = t;
                    return;
                }
                temp += "->";
                solve(root->left);
                solve(root->right);

                temp = t;
            }
        };

        solve(root);

        return res;
    }
};