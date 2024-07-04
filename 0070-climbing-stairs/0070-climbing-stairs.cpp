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

// class Solution {
// public:
//     unordered_map<int,int>dp;
//     int climbStairs(int n) {
//         if(n <= 0) return 1;

//         if(dp.count(n)) return dp[n];

//         int take_one_step = n > 0  ?climbStairs(n-1) : 0;
//         int take_two_steps = n > 1 ? climbStairs(n-2) : 0;

//         return dp[n] = take_one_step + take_two_steps; 
//     }
// };

// using tabulation

// class Solution {
// public:
//     int climbStairs(int n) {
//         int dp[n+1];
//         memset(dp, 0 ,sizeof(dp));

//         dp[0] = 1;
//         dp[1] = 1;

//         for(int i =2;i <= n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         } 
//         return dp[n];
//     }
// };


// tabulation -> improved  = spoce optimization

class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, curr =1;

        for(int i=2;i<=n;i++){
            int val = prev+curr;
            prev =curr;
            curr = val;
        } 

        return curr;

    }
};