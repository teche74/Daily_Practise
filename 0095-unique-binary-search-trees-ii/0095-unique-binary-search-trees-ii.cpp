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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode *>(int,int)> solve = [&](int low, int high)->vector<TreeNode*>{
            if(low > high) return {nullptr};
            vector<TreeNode*>res;

            for(int  i =low ; i <= high ; i++){
                vector<TreeNode*>left = solve(low , i-1);
                vector<TreeNode*> right = solve(i+1, high);
                

                for(auto l : left){
                    for(auto r : right){
                        TreeNode * root = new TreeNode(i);
                        root->left = l;
                        root->right = r;
                        res.push_back(root);
                    }
                }
            }

            return res;
        };

        return solve(1,n);
    }
};