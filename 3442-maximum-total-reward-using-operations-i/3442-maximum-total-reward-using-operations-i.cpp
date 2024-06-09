class Solution {
public:
    int solve(int index, vector<int>& arr, int res, unordered_map<int, unordered_map<int, int>>& dp) {
        if (index == arr.size()) {
            return res;
        }

        if (dp.count(index) && dp[index].count(res)) {
            return dp[index][res];
        }

        int pick = -1, not_pick = 0;

        if (arr[index] > res) {
            pick = solve(index + 1, arr, res + arr[index], dp);
            not_pick = solve(index+1,arr,res,dp);
        }
        else{
            not_pick = solve(index + 1, arr, res, dp);
        }

        dp[index][res] = max(pick, not_pick);
        return dp[index][res];
    }

    int maxTotalReward(vector<int>& arr) {
    
        sort(arr.begin(), arr.end());

        auto end_unique = unique(arr.begin(), arr.end());

        arr.erase(end_unique, arr.end());

        unordered_map<int, unordered_map<int, int>> dp;

        return solve(0, arr, 0, dp);
    }
};
