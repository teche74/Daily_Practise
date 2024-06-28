class Solution {
public:
    unordered_map<int,int>dp;
    int numTrees(int n) {
        if(n == 0 || n ==1) return 1;
        if(dp.count(n)) return dp[n];

        int res = 0;

        for(int i = 1; i <= n; i++){
            res += numTrees(i-1) * numTrees(n - i);
        }

        return dp[n] = res;
    }
};