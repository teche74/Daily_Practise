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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode *> map;
        unordered_set<int>seen;

        for(auto t : descriptions){
            int parent = t[0];
            int child = t[1];

            if(!map.count(parent)){
                map[parent]= new TreeNode(parent);
            }
            if(!map.count(child)){
                map[child] = new TreeNode(child);
            }

            if(t[2]){
                map[parent]->left = map[child];
            }
            else{
                map[parent]->right = map[child];
            }

            seen.insert(child);
        }

        for(auto t  : map){
            if(seen.find(t.first) == seen.end()){
                return t.second;
            }
        }

        return nullptr;
    }
};