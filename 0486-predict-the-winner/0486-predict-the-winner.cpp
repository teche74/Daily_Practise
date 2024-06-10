class Solution {
public:
    bool solve(vector<int> & nums, int low, int high, int sum1, int sum2, int turn){
        if(low > high){
            return sum1 >= sum2;
        }

        if(turn == 1){
            return solve(nums, low + 1, high, sum1 + nums[low], sum2, -turn) || 
                   solve(nums, low, high - 1, sum1 + nums[high], sum2, -turn);
        } else {
            return solve(nums, low + 1, high, sum1, sum2 + nums[low], -turn) && 
                   solve(nums, low, high - 1, sum1, sum2 + nums[high], -turn);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
       int low = 0, high = nums.size() - 1;
       return solve(nums, low, high, 0, 0, 1); 
    }
};
