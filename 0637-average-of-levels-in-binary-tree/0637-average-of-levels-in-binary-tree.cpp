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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;

        if(!root) return res;

        queue<TreeNode*>q;
        q.push(root);

        while(q.size()){
            double val = 0;
            int count = 0;
            int size =q.size();
            while(size--){
                val += q.front()->val;
                count++;
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }

                q.pop();
            }

            res.push_back(val/(double)(count));
        }
        
        return res;
    }
};