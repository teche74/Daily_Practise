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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>map;

        for(int i = 0 ; i < inorder.size() ; i++){
            map[inorder[i]] = i;
        }

        int index = inorder.size()-1;

        function<TreeNode* (int,int)> call = [&](int low, int high)->TreeNode*{
            if(low > high) return nullptr;

            int value = postorder[index--];
            int curr_index = map[value];

            TreeNode * root = new TreeNode(value);
            root->right = call(curr_index + 1 , high);
            root->left = call(low ,  curr_index-1);

            return root;
        };

        return call(0 , inorder.size()-1);
    }
};