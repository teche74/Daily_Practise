class Solution {
public:
    long long Check(const vector<int>& nums, long long val) {
        long long moves = 0;
        for(long long num : nums) {
            moves += abs(num - val);
        }
        return moves;
    }
    
    int minMoves2(vector<int>& nums) {
        long long low = *min_element(nums.begin(), nums.end());
        long long high = *max_element(nums.begin(), nums.end());
        long long res = INT_MAX;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            long long val = Check(nums, mid);
            
            long long val1 = Check(nums, mid + 1);
            
            if (val < val1) {
                res = min(res, val);
                high = mid - 1;
            } else {
                res = min(res, val1);
                low = mid + 1;
            }
        }
        return res;
    }
};
