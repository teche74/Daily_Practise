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
    void inorder(TreeNode * p , TreeNode * q , bool & val){
        if(!p && q || p && !q){
            val = false;
            return ;
        }

        if(p && q){
            inorder(p->left , q->left , val);
            if(p->val != q->val){
                val = false;
                return;
            }
            inorder(p->right , q->right,val);
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // parallel traversal
        bool val = true;
        inorder(p ,q,val);

        return val;
    }
};