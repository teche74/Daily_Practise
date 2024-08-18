class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();

        int sum = 0 , max_sum = INT_MIN ;

        for(int x : nums){
            sum+=x;

            if(sum < x){
                sum = x;
            }

            max_sum = max(sum , max_sum);
        }

        return max_sum;
    }
};