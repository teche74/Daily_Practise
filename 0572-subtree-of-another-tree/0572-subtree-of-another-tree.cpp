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
    bool Check(TreeNode * r1, TreeNode * r2){
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->val != r2->val) return false;

        bool left = Check(r1->left,r2->left);
        bool right = Check(r1->right,r2->right);

        return left && right;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(root->val == subRoot->val){
            if(Check(root, subRoot)) return true;
        }

        bool left = isSubtree(root->left , subRoot);
        bool  right = isSubtree(root->right,subRoot);

        return left || right; 
    }
};