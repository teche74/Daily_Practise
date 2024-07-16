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

    TreeNode* solve(int &index, int low , int high, vector<int> & postorder , unordered_map<int,int>& map ){  
        if(low > high) return nullptr;

        TreeNode * root = new TreeNode(postorder[index--]);
        int mid = map[root->val]; 

        root->right = solve(index,mid+1,high,postorder,map);
        root->left = solve(index,low, mid-1,postorder,map);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size() ;

        unordered_map<int,int>map;

        for(int i = 0; i < size; i++){
            map[inorder[i]] = i;
        }

        int index = size-1;

        return solve(index,0,size-1 , postorder,map);
    }
};