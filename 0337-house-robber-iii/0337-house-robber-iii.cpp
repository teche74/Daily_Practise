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
    // int solve(int index,vector<int>mon,vector<int> & dp){
    //     if(index >= mon.size()){
    //         return 0;
    //     }

    //     if(dp[index]!= -1) return dp[index];

    //     int take = mon[index] + solve(index+2,mon,dp);
    //     int not_take = solve(index+1,mon,dp);

    //     return dp[index] = max(take,not_take);  
    // }
    // int rob(TreeNode* root) {
    //     vector<int>res;

    //     queue<TreeNode*>q;

    //     q.push(root);

    //     while(!q.empty()){
    //         int size =q.size();
    //         int sum = 0;
    //         for(int i =0 ; i < size ; i++){
    //             TreeNode * front = q.front();
    //             q.pop();
    //             sum+=front->val;

    //             if(front->left){
    //                 q.push(front->left);
    //             }
    //             if(front->right){
    //                 q.push(front->right);
    //             }
    //         }
    //         res.emplace_back(sum);
    //     }
    //     vector<int>dp(res.size()+1,-1);
    //     return solve(0,res,dp);
    // }

    pair<int, int> robSub(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }
        
        auto left = robSub(root->left);
        auto right = robSub(root->right);
        
        int robCurrent = root->val + left.second + right.second;
        
        int notRobCurrent = max(left.first, left.second) + max(right.first, right.second);
        
        return {robCurrent, notRobCurrent};
    }
    
    int rob(TreeNode* root) {
        auto result = robSub(root);
        return max(result.first, result.second);
    }
};