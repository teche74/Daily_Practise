class Solution {
public:
    int solve(int index, vector<int> & nums, int sum, unordered_map<string, int> & memo ){
        if(index >= nums.size()){
            return sum == 0;
        }

        string key = to_string(index) + "_" + to_string(sum);

        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        int add =  solve(index+1 , nums ,sum - nums[index],memo);
        int sub =  solve(index+1,nums,sum + nums[index], memo);

        return memo[key] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(0, nums, target, memo);
    }
};