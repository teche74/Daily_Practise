class Solution {
public:
    #define ll long long
    unordered_map<int, int> mp;
    // vector<ll> dp; // Commented out dynamic vector
    ll dp[100000]; // Static array with a large fixed size

    ll solve(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        ll pick = 0, notPick = 0;
        int j = i+1;

        while( j < nums.size() && nums[j] <= nums[i]+2) j++;

        pick = nums[i] * 1LL * mp[nums[i]] + solve(j, nums);
        notPick = solve(i + 1, nums);
        return dp[i] = max(pick, notPick);
    }

    long long maximumTotalDamage(vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        sort(nums.begin(), nums.end());
        for (auto i : nums) mp[i]++;
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        // dp.resize(nums.size(), -1); // Commented out resizing
        memset(dp, -1, sizeof(dp)); // Initialize static array
        return solve(0, nums);
    }
};
