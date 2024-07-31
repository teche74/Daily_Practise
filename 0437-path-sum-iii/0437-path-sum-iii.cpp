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
    void solve(TreeNode * root , unordered_map<long long,int> & map, long long sum , long long & paths , int target){
        if(!root) return ;

        sum+=root->val;

        if(map.find(sum - target ) != map.end()){
            paths += map[sum - target];
        }

        map[sum]++;

        solve(root->left,map,sum , paths,target);
        solve(root->right,map,sum,paths,target);

        map[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        unordered_map<long long,int>map;
        map[0] = 1;

        long long paths = 0 , sum = 0;

        solve(root,map,sum, paths, targetSum);

        return paths; 
    }
};