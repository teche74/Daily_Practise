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
    void solve(TreeNode * root , int value , vector<int>temp , vector<vector<int>>&res){
        if(!root){
            return;
        }

        temp.emplace_back(root->val);
        value -= root->val;
        
        if(value == 0 && root->left == nullptr && root->right == nullptr )  {
            res.push_back(temp);
        }

        solve(root->left,value,temp,res);
        solve(root->right,value,temp,res);

        // value+=root->val;
        temp.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>>res;
        vector<int>temp;
        solve(root,targetSum,temp,res);
        return res;
    }
};