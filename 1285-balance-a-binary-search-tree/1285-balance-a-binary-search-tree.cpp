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
    void inorder_traversal(TreeNode * root, vector<int>&res){
        if(root){
            inorder_traversal(root->left,res);
            res.emplace_back(root->val);
            inorder_traversal(root->right,res);
        }
    }

    TreeNode * create(vector<int>&res, int low, int high){
        if(low >= high) return nullptr;
        int mid = low + (high - low)/2;

        TreeNode * left = create(res,low, mid);
        TreeNode * right = create(res,mid+1, high);
        TreeNode * root = new TreeNode (res[mid]);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>res;
        inorder_traversal(root,res);

        TreeNode * ans = create(res,0 ,res.size());   

        return ans; 
    }
};