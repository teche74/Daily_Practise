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
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }
    
private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};
        
        if (!node->left && !node->right) return {0};
        
        vector<int> left_d = dfs(node->left, distance, count);
        vector<int> right_d = dfs(node->right, distance, count);
        
        for (int ld : left_d) {
            for (int rd : right_d) {
                if (ld + rd + 2 <= distance) {
                    count++;
                }
            }
        }
        
        vector<int> dist;
        for (int d : left_d) {
            if (d + 1 < distance) dist.push_back(d + 1);
        }
        for (int d : right_d) {
            if (d + 1 < distance) dist.push_back(d + 1);
        }
        
        return dist;
    }
};
