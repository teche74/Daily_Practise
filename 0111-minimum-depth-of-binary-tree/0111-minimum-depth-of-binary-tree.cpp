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
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode *>q;
        q.push(root);
        int level = 1;

        while(q.size()){
            int size = q.size();

            while(size--){
                TreeNode * front = q.front();
                q.pop();

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }

                if(!front->left && !front->right){
                    return level;
                }
            }
            level++;
        }

        return level;
    }
};