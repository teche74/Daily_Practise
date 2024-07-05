// class Solution {
// public:
//     int solve(int index, vector<int>& paisa){
//         if(index >= paisa.size()){
//             return 0;
//         }

//         int take = paisa[index] + solve(index+2,paisa);
        
//         int not_take = solve(index + 1 , paisa);

//         return max(take , not_take);
//     }
//     int rob(vector<int>& nums) {
//         return solve(0, nums);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp(2, 0);

        for(int i = 0; i < nums.size() ; i++){
            int val = max(dp[1] ,dp[0]);
            dp[0] = dp[1] + nums[i];
            dp[1]  = val;
        }

        return max(dp[0], dp[1]);
    }
};