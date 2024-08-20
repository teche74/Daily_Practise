class Solution {
public:
    int check(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0;

        for (int i = start; i <= end; ++i) {
            int temp = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = temp;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int case1 = check(nums, 0, nums.size() - 2);
        
        int case2 = check(nums, 1, nums.size() - 1);

        return max(case1, case2);
    }
};
