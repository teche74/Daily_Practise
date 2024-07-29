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
    void solve(TreeNode * root , vector<int> & ele)
    {
        if(root){
            solve(root->left,ele);
            ele.emplace_back(root->val);
            solve(root->right,ele);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ele;

        solve(root, ele);

        int diff = INT_MAX;

        for(int i =1; i < ele.size() ; i++){
            diff = min(diff, ele[i] - ele[i-1]);
        }
        
        return diff;
    }
};