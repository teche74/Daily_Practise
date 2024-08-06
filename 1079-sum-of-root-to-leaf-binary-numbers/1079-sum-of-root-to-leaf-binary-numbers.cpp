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
    void preorder(TreeNode *root, int &  res , string curr){
        if(root){
            curr.push_back(root->val + '0');
            if(!root->left && !root->right){
                int ind = 0;
                // cout<<curr<<endl;
                for(int i = curr.size()-1 ; i >= 0 ; i--){
                    if(curr[i] == '1'){
                        res +=  1 << ind;
                    }
                    ind++;
                }
            }
            preorder(root->left,res,curr);
            preorder(root->right,res,curr);
            curr.pop_back();
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        preorder(root,res,"");
        return res;
    }
};