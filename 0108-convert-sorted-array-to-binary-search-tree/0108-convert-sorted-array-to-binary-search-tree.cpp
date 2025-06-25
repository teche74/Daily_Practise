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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        function<TreeNode * (int , int)> solve = [&](int low, int high)->TreeNode*{
            if(low > high) return nullptr;

            int mid = low + ((high - low) >> 1);

            TreeNode * root = new TreeNode(nums[mid]);
            root->left = solve(low, mid-1);
            root->right = solve(mid+1, high);

            return root;
        };
        return solve(0 , nums.size()-1);
    }
};