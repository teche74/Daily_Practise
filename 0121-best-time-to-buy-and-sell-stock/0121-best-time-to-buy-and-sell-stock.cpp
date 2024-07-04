//  recursive - > {TLE}

// class Solution {
// public:
//     int solve(int index , vector<int> & prices, int action){
//         if(index >= prices.size() || action == 0){
//             return 0;
//         }

//         int action1 = 0, action2 = 0;

//         if( !(action & 1) ){ // buy ka he
//             action1 += -prices[index]  + solve(index+1,prices, action-1);
//         }
//         else{ // sell ka he
//             action1 += prices[index] + solve(index+1,prices,action-1); 
//         }

//         // state leave kr do (no action).
//         action2+=solve(index+1,prices,action);
        
//         return max(action1,action2);
//     }
//     int maxProfit(vector<int>& prices) {

//         return solve(0 , prices, 2);        
//     }
// };

// memoization

// class Solution {
// public:

//     int solve(int index , vector<int> & prices, int action, int dp[][3]){
//         if(index >= prices.size() || action == 0){
//             return 0;
//         }

//         if(dp[index][action] != -1) return dp[index][action];

//         int action1 = 0, action2 = 0;

//         if( !(action & 1) ){ // buy ka he
//             action1 += -prices[index]  + solve(index+1,prices, action-1, dp);
//         }
//         else{ // sell ka he
//             action1 += prices[index] + solve(index+1,prices,action-1,dp); 
//         }

//         // state leave kr do (no action).
//         action2+=solve(index+1,prices,action,dp);
        
//         return dp[index][action] = max(action1,action2);
//     }
//     int maxProfit(vector<int>& prices) {
//         int dp[100007][3];
//         memset(dp,-1,sizeof(dp));
//         return solve(0 , prices, 2, dp);        
//     }
// };


//  tabulation (ese hogi tablation easy he copy me bna samjh jayega ) mle dera mera to leave kr next pe chalte

// class Solution {
// public:

//     int maxProfit(vector<int>& prices) {
//         int size = prices.size();

//         if (size <= 1) {
//             return 0; 
//         }

//         vector<vector<int>>dp(size,vector<int>(size,0));

//         int res = 0;

//         for(int i = 0; i < size-1 ; i++){ // i khredna decide krega  
            
//             for(int j = i+1; j < size ; j++){ // j bechna decide krega

//                 if(prices[i] < prices[j]){
//                     dp[i][j] = max(dp[i][j-1] , prices[j] - prices[i]);
//                 }
//                 res = max(res,dp[i][j]);
//             }
//         }

//         return res;
//     }
// };




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // two pointer

        int low = 0 , high = 0 , size = prices.size(), res = 0;

        while(high < size){
            if(prices[high] < prices[low]){
                low = high;
            }
            res = max(res, prices[high] - prices[low]);
            high++;
        } 
        return res;
    }
};