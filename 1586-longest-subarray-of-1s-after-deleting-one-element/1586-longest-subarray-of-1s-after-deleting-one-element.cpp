class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int low =  0, high = 0 , size = nums.size() ,  res = 0 ;
        int count_z = 0;

        while(high <size){
            count_z += (nums[high] == 0);

            while(count_z > 1){
                count_z -= (nums[low] == 0);
                low++;
            }

            res = max(res, high - low );
            high++;
        }
        return res;
    }
};