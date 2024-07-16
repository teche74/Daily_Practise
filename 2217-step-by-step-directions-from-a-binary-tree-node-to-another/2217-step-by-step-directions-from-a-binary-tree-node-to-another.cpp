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
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        
        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();
        
        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();
        
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path_to_start, path_to_dest;
        findPath(root, startValue, path_to_start);
        findPath(root, destValue, path_to_dest);
        
        int i = 0;
        while (i < path_to_start.size() && i < path_to_dest.size() && path_to_start[i] == path_to_dest[i]) {
            ++i;
        }
        string result(path_to_start.size() - i, 'U');
        
        result.append(path_to_dest.begin() + i, path_to_dest.end());
        
        return result;
    }
};