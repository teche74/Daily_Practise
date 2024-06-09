class Solution {
public:
    int binary(const vector<int>& arr, int target, int low) {
        int hi = arr.size();
        while (low < hi) {
            int mid = low + (hi - low) / 2;
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                hi = mid;
            }
        }
        return low;
    }
    int solve(int index, vector<int>& arr, int res, unordered_map<int, unordered_map<int, int>>& dp) {
        if (index >= arr.size()) {
            return res;
        }

        if (dp.count(index) && dp[index].count(res)) {
            return dp[index][res];
        }

        int pick = -1, not_pick = 0;

        int next_ind = binary(arr,res,index);

        if (next_ind < arr.size() && arr[next_ind] > res) {
            pick = solve(next_ind + 1, arr, res + arr[next_ind], dp);
            not_pick = solve(next_ind+1,arr,res,dp);
        }
        else{
            not_pick = solve(index + 1, arr, res, dp);
        }

        dp[index][res] = max(pick, not_pick);
        return dp[index][res];
    }

    int maxTotalReward(vector<int>& arr) {
    
        sort(arr.begin(), arr.end());

        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        unordered_map<int, unordered_map<int, int>> dp;

        return solve(0, arr, 0, dp);
    }
};
