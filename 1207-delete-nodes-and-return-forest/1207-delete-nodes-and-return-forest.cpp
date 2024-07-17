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
    TreeNode * solve(TreeNode * root, unordered_set<int> & st , vector<TreeNode*> & res){
        if(root == nullptr){
            return nullptr;
        }
        
        root->left = solve(root->left,st,res);
        root->right = solve(root->right,st,res); 

        if(st.count(root->val)){
            if(root->left){
                res.emplace_back(root->left);
            }

            if(root->right){
                res.emplace_back(root->right);
            }

            return nullptr;
        }

        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st(to_delete.begin(),to_delete.end());

        vector<TreeNode *>res;

        root = solve(root , st,res);

        if(root){
            res.emplace_back(root);
        }

        return res;
    }
};