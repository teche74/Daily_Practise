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
    void solve(TreeNode * root,  string temp , vector<string> & res){
        if(root){
            temp +=to_string(root->val);
            if(!root->left && !root->right){
                res.emplace_back(temp);
            }
            else{
                temp+="->";
            }
            solve(root->left,temp,res);
            solve(root->right,temp,res);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string temp = "";

        solve(root,temp,res);
        return res;
    }
};