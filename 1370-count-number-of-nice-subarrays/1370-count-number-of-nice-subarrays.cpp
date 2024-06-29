class Solution {
public:
    int solve(vector<int> & nums, int k){
        int low = 0,high = 0, size = nums.size(),res  = 0;
        int count_odd = 0;
        while(high < size){
            count_odd+=(nums[high] & 1);

            while(count_odd > k){
                count_odd-=(nums[low] & 1);
                low++;
            }
            res+=(high - low+1);
            high++;
        } 

        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        // inclusion -exclusion

        // k - (k-1)

        return solve(nums, k) - solve(nums,k-1);
    }
};