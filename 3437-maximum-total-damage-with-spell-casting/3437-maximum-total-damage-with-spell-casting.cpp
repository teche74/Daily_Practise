class Solution {
public:
    #define ll long long
    unordered_map<int, int> mp;
    ll dp[100000]; 

    int BinSrch(vector<int>& nums, int target){
        int low = 0, high = nums.size(); // high should be nums.size() not nums.size()-1

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        } 
        return high; // Return high, not mid
    }

    ll solve(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        ll pick = 0, notPick = 0;
        
        int t = BinSrch(nums, nums[i] + 2);

        int j = t; // No need to subtract nums.begin()

        pick = nums[i] * 1LL * mp[nums[i]] + solve(j, nums);
        notPick = solve(i + 1, nums);
        return dp[i] = max(pick, notPick);
    }

    long long maximumTotalDamage(vector<int>& nums) {
        ios_base::sync_with_stdio(0); cin.tie(0);
        sort(nums.begin(), nums.end());
        for (auto i : nums) mp[i]++;
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        memset(dp, -1, sizeof(dp)); // Initialize static array
        return solve(0, nums);
    }
};
