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
    TreeNode * solve(int  & index , vector<int> & nums, int low, int high ){
        if(index >= nums.size()) return nullptr;

        int val = nums[index];

        if(val > high || val< low) return nullptr;

        index++;

        TreeNode  *root = new TreeNode(val); 
        root->left = solve(index , nums,low , val);
        root->right = solve(index, nums, val, high);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve( index, preorder ,  INT_MIN, INT_MAX);
    }
};