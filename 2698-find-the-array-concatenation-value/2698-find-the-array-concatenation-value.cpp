class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res = 0;

        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            if (low == high) {
                res += nums[low];
            } else {
                string concatenatedValue = to_string(nums[low]) + to_string(nums[high]);
                res += stoll(concatenatedValue);
            }
            low++;
            high--;
        }
        return res;
    }
};