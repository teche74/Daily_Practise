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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string temp;

        function<void(TreeNode*)>call = [&](TreeNode* curr){
            if(curr){
                string prev = temp;
                temp += to_string(curr->val);
                if(!curr->left && !curr->right){
                    res.push_back(temp);
                    temp = prev;
                    return;
                }
                temp+="->";
                call(curr->left);
                call(curr->right);
                temp  = prev;
            }
        };

        call(root);
        return res;
    }
};