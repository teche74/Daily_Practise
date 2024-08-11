class Solution {
public:
    int solve(vector<int> & nums, int limit ){
        int low = 0 , high = 0 , size = nums.size(), res = 0, odds= 0;

        while(high < size){
            odds += (nums[high] & 1);

            while(odds > limit){
                odds -= (nums[low] & 1);
                low++;
            }
            res+=(high - low + 1);
            high++;
        }
        return res;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums,k-1);
    }
};