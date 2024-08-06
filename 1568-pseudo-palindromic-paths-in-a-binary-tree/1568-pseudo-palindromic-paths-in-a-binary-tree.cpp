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
    void solve(TreeNode  *root, unordered_map<int,int> & map, int  & res){
        if(root){
            map[root->val]++;
            if( !root->left && !root->right){
                int count = 0;

                for(auto t : map){
                    count +=(t.second % 2);
                }

                if(count <=1){
                    res++;
                }
            }
            solve(root->left,map,res);
            solve(root->right,map,res);
            map[root->val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0 ;
        unordered_map<int,int>map;
        solve(root,map,res);

        return res;
    }
};