class Solution {
public:

    int numTrees(int n) {

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

        // return solve(1,n).size();

        int dp[20];
        memset(dp , 0 ,sizeof(dp));

        dp[0] = 1;
        dp[1] = 1;

        for(int total_nodes = 2; total_nodes <= n; total_nodes++){
            for(int left = 0 ; left < total_nodes ; left++){
                int right = total_nodes - left - 1;
                dp[total_nodes]+= (dp[left] * dp[right]);
            }
        }

        return dp[n];
    }
};