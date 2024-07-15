class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
         int size1 = s1.size(), size2 = s2.size();
        int reach = s3.size();

        if (size1 + size2 != reach) return false;

        int dp[101][101];
        memset(dp, -1, sizeof(dp));

        function<bool(int, int, int)> solve = [&](int i, int j, int k) -> bool {
            if (k == reach) {
                return true;
            }

            if (dp[i][j] != -1) return dp[i][j] == 1;

            bool take_first = false, take_second = false;

            if (i < size1 && s1[i] == s3[k]) {
                take_first = solve(i + 1, j, k + 1);
            }
            if (j < size2 && s2[j] == s3[k]) {
                take_second = solve(i, j + 1, k + 1);
            }

            dp[i][j] = take_first || take_second ? 1 : 0;
            return dp[i][j] == 1;
        };

        return solve(0, 0, 0);
    }
};