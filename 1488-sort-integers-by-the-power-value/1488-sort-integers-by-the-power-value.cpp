class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> res;

        for (int i = lo; i <= hi; ++i) {
            res.emplace_back(i);
        }

        int dp[10000004];
        memset(dp, -1, sizeof(dp));

        function<int(int)> compute = [&](int num) {
            if (num == 1) {
                return 0;
            }

            if (num < 1000 && dp[num] != -1) return dp[num];

            int steps;
            if (num % 2 == 0) {
                steps = 1 + compute(num / 2);
            } else {
                steps = 1 + compute(3 * num + 1);
            }

            if (num < 1000) dp[num] = steps;
            return steps;
        };

        for (int i = lo; i <= hi; ++i) {
            compute(i);
        }

        sort(res.begin(), res.end(), [&](int x, int y) {
            int val1 = compute(x);
            int val2 = compute(y);
            return val1 == val2 ? x < y : val1 < val2;
        });

        return res[k - 1];
    }
};
