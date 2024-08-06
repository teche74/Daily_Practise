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
        unordered_map<int,pair<TreeNode * ,int>> map;

        queue<pair<TreeNode *,int>> q;
        
        q.push({root,0});

        while(!q.empty()){
            int size =q.size();

            for(int i =0 ; i <size ; i++){
                TreeNode * front = q.front().first;
                int level = q.front().second;
                q.pop();

                if(front->left){
                    map[front->left->val] = {front,level+1};
                    q.push({front->left,level+1});
                }
                if(front->right){
                    map[front->right->val] = {front,level+1};
                    q.push({front->right,level+1});
                }
            }
        }

        return map[x].second == map[y].second && map[x].first != map[y].first;
    }
};