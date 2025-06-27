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
    void call(TreeNode * root, vector<int> & temp){
        if(root){
            if(!root->left && !root->right){
                temp.push_back(root->val);
            }
            call(root->left, temp);
            call(root->right,temp);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> x , y;

        call(root1,x);
        call(root2,y);

        if(x.size() != y.size()) return false;

        for(int i = 0 ; i < x.size() ; i++){
            // cout<<x[i]<<" "<<y[i]<<endl;
            if(x[i] != y[i]) return false;
        }

        return true;
    }
};