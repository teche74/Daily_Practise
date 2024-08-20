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
    void solve(TreeNode * root, int val , vector<int> temp , vector<vector<int>> & res){
        if(root){
            temp.emplace_back(root->val);
            val -=root->val;
            if(!root->left && !root->right){

                if(!val){
                    res.emplace_back(temp);
                }
            }
            solve(root->left , val ,temp,res);
            solve(root->right,val ,temp,res);
            temp.pop_back();
            val+=root->val;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>temp;

        solve(root,targetSum , temp,res);
        return res;
    }
};