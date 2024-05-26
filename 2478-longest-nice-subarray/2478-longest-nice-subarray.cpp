class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int low = 0 ,  high = 0 , size = nums.size() ;
        int cond = 0, res = 0;

        while(high < size){
            
            while(nums[high] & cond){
                cond ^=nums[low];
                low++;
            }
            
            cond = cond | nums[high];

            res = max(res, high - low + 1 );
            high++;
        }
        return res;
    }
};