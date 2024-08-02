/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void make_parent_connection(TreeNode * root,unordered_map<TreeNode *, TreeNode *>& map ){
        queue<TreeNode *> q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ;i < size; i++){
                TreeNode * parent = q.front();
                q.pop();

                if(parent->left){
                    q.push(parent->left);
                    map[parent->left] = parent;
                }
                
                if(parent->right){
                    q.push(parent->right);
                    map[parent->right] = parent;
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map<TreeNode *, TreeNode *> parent;

        make_parent_connection(root,parent);

        //  up left right call marta rhe

        queue<pair<TreeNode *,int>> q;
        map<TreeNode * ,bool>vis;

        vector<int>res;

        q.push({target,0});

        while(!q.empty()){
            TreeNode * curr = q.front().first;
            int dist = q.front().second;
            vis[curr] = true;
            q.pop();

            if(dist > k){
                return res;
            }
            if(dist <= k){
                if(dist == k)res.emplace_back(curr->val);
                if(parent[curr]  && !vis[parent[curr]]){
                    q.push({parent[curr],dist+1});
                }
                if(curr->left && !vis[curr->left]){
                    q.push({curr->left,dist+1});
                }

                if(curr->right && !vis[curr->right]){
                    q.push({curr->right,dist+1});
                }
            }
        }

        return res;
    }
};