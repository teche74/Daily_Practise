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
        if(!root) return {};
        vector<vector<int>>res;

        queue<TreeNode *>q;
        bool rev = false;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int>lev;
            for(int i =0 ;i < size ;i++){
                TreeNode * temp = q.front();
                q.pop();
                lev.emplace_back(temp->val);
                
                if(temp->left) q.push(temp->left); 
                if(temp->right) q.push(temp->right);
                
            }
            if(rev){
                reverse(lev.begin(),lev.end());
            }
            res.emplace_back(lev);
            rev = !rev;
        }

        return res;
    }
};