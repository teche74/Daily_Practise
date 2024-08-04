class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int del =1;
        int low = 0,  high = 0 , size = nums.size(), res = 0 ,count = 0;

        while(high < size){
            count += (nums[high] == 1);
            del -= (nums[high] == 0);

            while(del < 0){
                count -=(nums[low] == 1);
                del +=(nums[low] == 0);
                low++;
            }
            res = max(res,count);
            high++;
        }  
        return (low == 0  && del ==1 )? res-1 : res;
    }
};