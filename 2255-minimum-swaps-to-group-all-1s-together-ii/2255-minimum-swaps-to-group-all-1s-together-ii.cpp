class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total = ::accumulate(nums.begin(), nums.end() ,0);

        int low = 0 , high = 0 , size = nums.size(), res = nums.size(), count  = 0;

        while(high < size * 2){
            count += (nums[high % size] == 1);

            while(high - low +1 >= total){
                res = min(res, (high - low +1) - count );
                count -= (nums[low % size] == 1);
                low++;
            }
            
            
            high++;
        }
        return res;
    }
};