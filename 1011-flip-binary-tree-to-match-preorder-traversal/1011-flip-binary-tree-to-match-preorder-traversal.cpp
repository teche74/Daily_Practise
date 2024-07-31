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
    bool solve(TreeNode *root, int & index, vector<int> & voyage , vector<int> & res){
        if(!root) return true;
        if(root->val != voyage[index++]) return false;

        if(root->left && root->left->val != voyage[index]){
            res.emplace_back(root->val);
            // revrse traversing first right then left.
            return solve(root->right,index,voyage,res) && solve(root->left,index, voyage,res);
        }
        else{
            // do  asusual travresing 
            return solve(root->left,index, voyage,res) && solve(root->right,index,voyage,res);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int index = 0 ;
        vector<int>res;
        if(solve(root,index, voyage,res)){
            return res;
        }
        
        return {-1};
    }
};