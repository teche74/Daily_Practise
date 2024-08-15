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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return -1; 
        }

        queue<TreeNode * >q;
        q.push(root);

        int res = 0;

        while(q.size()){
            int size  = q.size();
            bool first = true;
            while(size--){ 
                TreeNode * front = q.front(); q.pop();
                if(first){
                    res = front->val;
                    first = !first;
                }

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
        }

        return res;
    }
};