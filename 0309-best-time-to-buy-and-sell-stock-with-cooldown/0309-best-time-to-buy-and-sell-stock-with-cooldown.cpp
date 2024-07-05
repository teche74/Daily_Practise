class Solution {
public:
    int solve(int index, vector<int>& prices, int opers, vector<vector<int>>& dp) {
        if (index >= prices.size()) return 0;
        if (dp[index][opers] != -1) return dp[index][opers];

        int take = 0, not_take = 0;

        if (!(opers & 1)) {
            take = -prices[index] + solve(index + 1, prices, opers - 1, dp);
        } else {
            take = prices[index] + solve(index + 2, prices, opers - 1, dp);
        }
        not_take = solve(index + 1, prices, opers, dp);

        return dp[index][opers] = max(take, not_take);
    }

    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int opers = size;
        while (opers % 2 != 0) opers--;

        vector<vector<int>> dp(size, vector<int>(opers + 1, -1));
        return solve(0, prices, opers, dp);
    }
};
