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
    int pathSum(TreeNode* root, int target) {
        unordered_map<long long,int>map;
        long long sum = 0 , res =0;
        map[0] = 1;

        function<void(TreeNode* , long long )> solve = [&](TreeNode * trav , long long sum){
            if(trav){
                sum += trav->val;
                if(map.find(sum - target) != map.end()){
                    res += map[sum - target];
                }
                map[sum]++;
                solve(trav->left, sum);
                solve(trav->right , sum);
                map[sum]--;
                // sum -= trav->val;
            }
        };

        solve(root , sum);
        return res;
    }
};