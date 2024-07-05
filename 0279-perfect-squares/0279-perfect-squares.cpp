// class Solution {
// public:
//     int solve(int index, int val){
//         if(val == 0){
//             return 0;
//         }
        
//         if(index * index > val) return 1e8;

//         int take = 0 , not_take = 0;

//         if(index * index <= val){
//             take = 1 + solve(index , val - (index * index));
//         }

//         not_take = solve(index + 1,val);

//         return min(take, not_take);

//     }
//     int numSquares(int n) {
//         return solve(1,n);
//     }
// };

class Solution {
public:
    int solve(int val, vector<int>&dp){
        int count = INT_MAX;
        int res = 0;
        if(val == 0){
            return 0;
        }

        if(dp[val] != -1) return dp[val];

        for(int i =1; i <= sqrt(val); i++){
            res  = 1 + solve( val - (i*i) ,dp );
            count = min(count ,res);
        }

        return dp[val] = count;

    }
    int numSquares(int n) {
        vector<int>dp(n + 1,-1); 
        return solve(n, dp);
    }
};