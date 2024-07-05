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
    unordered_map<int,vector<TreeNode* >>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *>res;

        if(n % 2 == 0) return res;

        if(n == 1){
            return {new TreeNode(0)};
        }

        if(dp.count(n)) return dp[n];

        for(int i = 1; i < n ;i+=2){
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n-i-1);

            for(auto t : left){
                for(auto l : right){
                    TreeNode * root = new TreeNode(0);
                    root->left = t;
                    root->right = l;
                    res.emplace_back(root); 
                }
            }
        }
        return dp[n] = res;
    }
};