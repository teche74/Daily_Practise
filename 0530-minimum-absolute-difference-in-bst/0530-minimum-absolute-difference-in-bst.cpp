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
    void solve(TreeNode * root , int & prev , int  & res){
        if(root){
            solve(root->left , prev,res);
            if(prev != -1 ) res = min(res, root->val - prev );
            prev = root->val;
            solve(root->right,prev,res);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1 , res = INT_MAX;
        solve(root,prev,res);

        return res;
        
    }
};


// sara array chahiye hi ni tha bas previous to chahiye tha /.


// class Solution {
// public:
//     void solve(TreeNode * root , vector<int> & ele)
//     {
//         if(root){
//             solve(root->left,ele);
//             ele.emplace_back(root->val);
//             solve(root->right,ele);
//         }
//     }
//     int getMinimumDifference(TreeNode* root) {
//         vector<int>ele;

//         solve(root, ele);

//         int diff = INT_MAX;

//         for(int i =1; i < ele.size() ; i++){
//             diff = min(diff, ele[i] - ele[i-1]);
//         }
        
//         return diff;
//     }
// };