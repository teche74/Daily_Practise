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
    TreeNode * solve(int & index, vector<int> & pre , long mini , long maxi){
        if(index >= pre.size()) return nullptr;

        if(pre[index] >= maxi || pre[index] <= mini) return nullptr;

        TreeNode * root =new TreeNode(pre[index++]);

        root->left = solve(index,pre,mini,root->val);
        root->right = solve(index,pre,root->val ,maxi);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(index, preorder, LONG_MIN , LONG_MAX );
    }
};