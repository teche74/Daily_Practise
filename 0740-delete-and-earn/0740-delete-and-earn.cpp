class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int size = *max_element(nums.begin(), nums.end());
        
        vector<int> points(size + 1, 0);
        
        for (int num : nums) {
            points[num] += num;
        }

        vector<int> dp(size + 1, 0);
        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for (int i = 2; i <= size; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }

        return dp[size];
    }
};