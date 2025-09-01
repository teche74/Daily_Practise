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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>temp;
        if(!root) return res;
        
        queue<TreeNode*>q;
        q.push(root);
        bool rev = false;

        while(q.size()){
            int size = q.size();
            temp.clear();
            while(size--){
                TreeNode* front = q.front();q.pop();
                temp.push_back(front->val);

                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }
            }
            if(rev){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            rev = !rev;
        }

        return res;
    }
};