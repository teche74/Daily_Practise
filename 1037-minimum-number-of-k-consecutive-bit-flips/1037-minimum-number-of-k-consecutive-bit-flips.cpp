class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isflipped(n, 0);
        int flip_count = 0;
        int curr_flips = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                curr_flips -= isflipped[i - k];
            }
            if ( !((nums[i] + curr_flips) & 1) ) {
                if (i + k > n) return -1;
                isflipped[i] = 1;
                curr_flips += 1;
                flip_count += 1;
            }
        }
        return flip_count;
    }
};
