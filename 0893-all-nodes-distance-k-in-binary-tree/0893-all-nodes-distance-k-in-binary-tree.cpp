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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};

        unordered_map<int,vector<int>>graph;

        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;

        while(q.size()){
            int size = q.size();
            while(size--){
                TreeNode* front = q.front();q.pop();

                if(front->left){
                    q.push(front->left);
                    graph[front->val].push_back(front->left->val);
                    graph[front->left->val].push_back(front->val);
                }

                if(front->right){
                    q.push(front->right);
                    graph[front->val].push_back(front->right->val);
                    graph[front->right->val].push_back(front->val);
                }
            }
        }

        unordered_set<int>vis;
        int level = 0;
        
        queue<int>q2;
        q2.push(target->val);
        vis.insert(target->val);

        while(q2.size()){
            int size =q2.size();

            if (level == k) {
                while (!q2.empty()) {
                    res.push_back(q2.front());
                    q2.pop();
                }
                break;
            }

            while(size--){
                int node = q2.front(); q2.pop();
                for (int nei : graph[node]) {
                    if (!vis.count(nei)) {
                        vis.insert(nei);
                        q2.push(nei);
                    }
                }
            }
            level++;
        }

        return res;
    }
};