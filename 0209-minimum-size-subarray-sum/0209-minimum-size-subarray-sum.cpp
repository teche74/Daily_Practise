class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0 , high = 0 , sum = 0 , size = nums.size();
        int res = size+1;
        while(high  < size){
            sum += nums[high];

            while(sum >= target){
                res = min(res , high - low +1);
                sum -= nums[low];
                low++;
            }

            high++;
        }

        return res == size+1 ? 0 : res;
    }
};