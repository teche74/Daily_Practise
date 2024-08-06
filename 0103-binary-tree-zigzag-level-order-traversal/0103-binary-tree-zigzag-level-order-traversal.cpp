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
        if(!root) return res;

        queue<TreeNode*> q;
        bool check = false;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            for(int i =0 ;i < size ; i++){
                TreeNode * front = q.front();
                q.pop();
                temp.emplace_back(front->val);

                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            if(check){
                reverse(temp.begin(),temp.end());
            }
            check = !check;
            res.emplace_back(temp);
        }
        return res;
    }
};