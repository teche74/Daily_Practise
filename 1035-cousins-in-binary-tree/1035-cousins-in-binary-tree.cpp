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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int,pair<TreeNode * , int>>map; // current_value  : < uska parent , uska level>;

        queue<TreeNode * > q;
        
        q.push(root);
        map[root->val] = {nullptr , 0};
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i  < size ; i++){
                TreeNode * front = q.front();
                q.pop();

                if(front->left){
                    q.push(front->left);
                    map[front->left->val] = {front , level+1}; 
                }
                if(front->right){
                    q.push(front->right);
                    map[front->right->val] = {front, level+1};
                }
            }
            level++;
        }

        return !(map[x].first == map[y].first || map[x].second != map[y].second);
    }
};