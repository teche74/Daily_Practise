class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        unordered_map<string, long long> memo;

        function<long long(int, bool)> dfs = [&](int ind, bool lastp) -> long long {
            if (ind == n) {
                return 0;
            }

            string key = to_string(ind) + "-" + to_string(lastp);
            if (memo.find(key) != memo.end()) {
                return memo[key];
            }

            if (lastp) {
                long long take = dfs(ind + 1, false) - nums[ind];
                long long skip = dfs(ind + 1, true) + nums[ind];
                memo[key] = max(take, skip);
            } else {
                memo[key] = dfs(ind + 1, true) + nums[ind];
            }

            return memo[key];
        };

        return dfs(0, false);
    }
};
