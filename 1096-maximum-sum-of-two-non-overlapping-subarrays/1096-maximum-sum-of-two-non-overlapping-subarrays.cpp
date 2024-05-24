class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int size = nums.size();
        
        vector<int> prefix(size + 1, 0);
        for (int i = 0; i < size; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        auto getMaxSum = [&](int low, int high) {
            int maxL = 0, maxSum = 0;
            for (int i = low + high; i <= size; i++) {
                maxL = max(maxL, prefix[i - high] - prefix[i - high - low]);
                maxSum = max(maxSum, maxL + prefix[i] - prefix[i - high]);
            }
            return maxSum;
        };
        
        return max(getMaxSum(firstLen, secondLen), getMaxSum(secondLen, firstLen));
    }
};