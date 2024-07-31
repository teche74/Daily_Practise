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
    TreeNode * find(TreeNode * temp){
        while(temp->left!= nullptr){
            temp=temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root->val < key)
            root->right = deleteNode(root->right,key);
        else if(root->val > key) 
            root->left =  deleteNode(root->left,key);
        else{
            // if not child
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(!root->left ){
                TreeNode * ptr = root->right;
                delete root;
                return ptr;
            }
            else if(!root->right){
                TreeNode * ptr = root->left;
                delete root;
                return ptr; 
            }
            else{
                TreeNode  *temp = find(root->right);
                root->val = temp->val;
                root->right =  deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
};