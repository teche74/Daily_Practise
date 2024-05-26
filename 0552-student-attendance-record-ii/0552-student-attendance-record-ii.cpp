#include <vector>
class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<vector<int>>> memo;

    int solve(int n, int absent_remain, int late_remain) {
        if (n == 0) {
            return 1;
        }

        if (memo[n][absent_remain][late_remain] != -1) {
            return memo[n][absent_remain][late_remain];
        }

        int total = 0;

        total += solve(n - 1, absent_remain, 2);
        total %= MOD;

        if (absent_remain > 0) {
            total += solve(n - 1, absent_remain - 1, 2);
            total %= MOD;
        }

        if (late_remain > 0) {
            total += solve(n - 1, absent_remain, late_remain - 1);
            total %= MOD;
        }

        memo[n][absent_remain][late_remain] = total;
        return total;
    }

public:
    int checkRecord(int n) {
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2,vector<int>(3, -1)));
        return solve(n, 1, 2);
    }
};
