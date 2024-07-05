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

    int solve(int index, vector<int>& paisa, vector<int> & dp){
        if(index >= paisa.size()){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int take = paisa[index] + solve(index+2,paisa,dp);
        
        int not_take = solve(index + 1 , paisa,dp);

        return dp[index] = max(take , not_take);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp(size+1,-1);
        return solve(0, nums, dp);
    }
};