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
    TreeNode * solve(vector<int>nums , int low, int high){

        if(low > high) return nullptr;

        int max_ind = low;

        for(int i = low+1; i <= high ; i++){
            if(nums[i] > nums[max_ind]){
                max_ind = i;
            }
        }

        TreeNode * root = new TreeNode(nums[max_ind]);
        root->left = solve(nums, low, max_ind-1);
        root->right = solve(nums, max_ind+1,high);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int size = nums.size();
        return solve(nums, 0 ,size-1);
    }
};