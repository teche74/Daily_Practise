class Solution {
public:
    int solve(int index, vector<int>& arr, int oper, vector<vector<int>>& memo) {
        if (index == arr.size() || oper == 0) {
            return 0;
        }
        if (memo[index][oper] != -1) {
            return memo[index][oper];
        }

        int pick, not_pick;
        if (!(oper & 1) ) {
            pick = -arr[index] + solve(index + 1, arr, oper - 1, memo);
        } else {
            pick = arr[index] + solve(index + 1, arr, oper - 1, memo);
        }
        not_pick = solve(index + 1, arr, oper, memo);

        return memo[index][oper] = max(pick, not_pick);
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int maxProfit = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        vector<vector<int>> memo(n, vector<int>(k * 2 + 1, -1));
        return solve(0, prices, k * 2, memo);
    }
};
