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
    void solve(TreeNode * root , string curr , string  & res){
        if(root){
            curr.push_back(root->val + 'a');
            if(!root->left && !root->right){
                string t =curr;
                reverse(t.begin(),t.end());
                if(res.empty() || res > t){
                    res = t;
                }
            }
            solve(root->left, curr, res);
            solve(root->right , curr,res);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string res = "";

        solve(root,"",res);

        return res;
    }
};