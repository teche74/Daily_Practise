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
    TreeNode * solve(int  & index, vector<int>& postorder , unordered_map<int,int> & map , int low , int high){
        if(low > high) return nullptr;

        int val = postorder[index--];

        TreeNode * root = new TreeNode (val);

        root->right = solve(index, postorder, map,map[val]+1, high);
        root->left = solve(index, postorder, map, low, map[val]-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();

        unordered_map<int,int>map;

        for(int i = 0 ; i< size; i++){
            map[inorder[i]] = i;
        }

        int index = size-1;

        return solve(index,postorder,map,0 ,size-1);
    }
};