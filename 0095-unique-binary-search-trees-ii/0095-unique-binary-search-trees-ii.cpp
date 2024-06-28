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
    map<pair<int,int>,vector<TreeNode*>>map;
    vector<TreeNode*> solve(int low, int high){
        // vector<TreeNode*>res;

        // if(low > high) {
        //     res.emplace_back(nullptr);
        //     return res;
        // } 

        // for(int i= low ; i <= high ; i++){
        //    vector<TreeNode *>left = solve(low,i-1);
        //    vector<TreeNode*> right = solve(i+1,high);

        //    for(auto t : left){
        //         for(auto r : right){
        //              TreeNode * root = new TreeNode(i,t,r);
        //              res.push_back(root);
        //         }
        //    }
        // }
        // return res;

        vector<TreeNode*>res;

        if(low > high) {
            res.emplace_back(nullptr);
            return res;
        } 

        if(map.find({low,high}) != map.end()) return map[{low,high}]; 

        for(int i= low ; i <= high ; i++){
           vector<TreeNode *>left = solve(low,i-1);
           vector<TreeNode*> right = solve(i+1,high);

           for(auto t : left){
                for(auto r : right){
                     TreeNode * root = new TreeNode(i,t,r);
                     res.push_back(root);
                }
           }
        }
        return map[{low, high}] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        int low{1}, high{n};

        return solve(low, high);
    }
};