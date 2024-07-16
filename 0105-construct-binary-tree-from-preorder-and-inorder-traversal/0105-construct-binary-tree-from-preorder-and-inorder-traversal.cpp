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

    TreeNode * solve(int & index, int low, int high, vector<int> & pre , unordered_map<int,int> &map ){
        if(low > high) return nullptr;

        TreeNode * root = new TreeNode(pre[index++]);

        int mid = map[root->val];

        root->left = solve(index, low , mid-1,pre,map);
        root->right =solve(index , mid+1, high , pre, map);

        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>map;

        int size = inorder.size();

        for(int i =0; i < size; i++){
            map[inorder[i]] = i;
        }

        int index = 0;

        return solve(index , 0 , size-1, preorder,map);
        
    }
};