class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane
        int sum = 0 , max_sum = INT_MIN;

        for(int x :  nums){
            sum+=x;

            if(sum < x){
                sum = x;
            }

            max_sum = max(max_sum , sum);
        } 

        return max_sum;
    }
};