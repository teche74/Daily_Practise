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
    void solve(TreeNode *root, int  & sum , TreeNode * prev){
        if(root){
            if(prev && prev-> left == root && root->left == nullptr  && root->right == nullptr){
                sum+=root->val;
            }
            prev =root;
            solve(root->left,sum,prev);
            solve(root->right,sum,prev);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // int sum = 0;

        // if(!root) return sum;

        // queue<TreeNode*>q;

        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();

        //     for(int i = 0 ; i <size ; i++){
        //         TreeNode * front = q.front();
        //         q.pop();

        //         if(front->left){
        //             if(!front->left->right && !front->left->left)
        //                 sum+=front->left->val;

        //             q.push(front->left);
        //         }
        //         if(front->right){
        //             q.push(front->right);
        //         }
        //     }
        // }

        // return sum;

        int sum = 0 ;
        solve(root, sum , nullptr);

        return sum;
    }
};