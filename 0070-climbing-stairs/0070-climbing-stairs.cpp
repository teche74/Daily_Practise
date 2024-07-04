// using recursive 

// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n <= 0) return 1;

//         int take_one_step = n > 0  ?climbStairs(n-1) : 0;
//         int take_two_steps = n > 1 ? climbStairs(n-2) : 0;

//         return take_one_step + take_two_steps; 
//     }
// };

// using memoization

class Solution {
public:
    unordered_map<int,int>dp;
    int climbStairs(int n) {
        if(n <= 0) return 1;

        if(dp.count(n)) return dp[n];

        int take_one_step = n > 0  ?climbStairs(n-1) : 0;
        int take_two_steps = n > 1 ? climbStairs(n-2) : 0;

        return dp[n] = take_one_step + take_two_steps; 
    }
};