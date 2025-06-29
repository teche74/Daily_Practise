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
    int get_val(string val){
        int res = 0;
        int index = 0;
        for(int i  = val.size()-1 ; i >= 0 ; i--){
            if(val[i]  == '1'){
                res += pow(2,index);
            }
            index++;
        }
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        string val = "";
        int res = 0;

        function<void(TreeNode *)> solve = [&](TreeNode * trav){
            if(trav){
                val.push_back(trav->val + '0');
                if(!trav->left && !trav->right){
                    res += get_val(val);
                }
                else{
                    solve(trav->left);
                    solve(trav->right);
                }
                val.pop_back();
            }
        };

        solve(root);

        return res;
    }
};