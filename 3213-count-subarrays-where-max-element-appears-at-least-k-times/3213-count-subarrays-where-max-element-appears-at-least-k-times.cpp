class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        int val = *max_element(nums.begin(), nums.end());
        long long low = 0 , high = 0 , count = 0 , res = 0;

        while(high < size){
            count+=(nums[high] == val);

            while(count >= k){
                res += size-high;
                count-=(nums[low] == val);
                low++;
            }

            high++;
        }
        return res;
    }
};