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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;

        if(!root) return {};

        queue<TreeNode*>q;
        q.push(root);


        while(q.size()){
            int size = q.size();
            int index = 0;
            while(index < size){
                TreeNode* front = q.front();q.pop();

                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }

                if(index == size-1){
                    res.push_back(front->val);
                }

                index++;
            }
        }

        return res;
    }
};