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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>index_map;

        for(int i = 0 ; i  < inorder.size() ; i++){
            index_map[inorder[i]] = i;
        }

        int index = 0;

        function<TreeNode*(int,int)> call = [&](int low, int high)->TreeNode*{
            if(low > high) return nullptr;

            int value = preorder[index++];
            int ind = index_map[value];

            TreeNode * root = new TreeNode(value);
            root->left = call(low, ind-1);
            root->right = call(ind+1 , high);

            return root;
        };

        return call(0,  inorder.size()-1);
    }
};