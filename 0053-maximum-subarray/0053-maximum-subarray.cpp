class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , res = INT_MIN , size = nums.size();

        for(int i =0; i <size ; i++){
            sum += nums[i];

            if(sum < nums[i] ){
                sum = nums[i];
            }

            res  = max(res, sum);
        }

        return  res;
    }
};