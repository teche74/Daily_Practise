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
    TreeNode * solve(int low, int & index, int high , unordered_map<int,int> & map, vector<int> & preorder){
        if(low > high) return nullptr;

        TreeNode  * root = new TreeNode (preorder[index++]);

        int mid = map[root->val];

        root->left = solve(low,index, mid-1,map,preorder);
        root->right = solve(mid+1,index, high,map,preorder);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>map;

        for(int i = 0;  i < inorder.size() ; i++){
            map[inorder[i]] = i;
        }

        int index = 0;

        return solve(0, index , inorder.size()-1, map,preorder);

    }
};