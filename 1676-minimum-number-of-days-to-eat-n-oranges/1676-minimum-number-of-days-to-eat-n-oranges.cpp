class Solution {
public:
    unordered_map<int,int>dp;
    int solve(int val){

        if(val == 0){
            return 0;
        }
        if(val == 1){
            return 1;
        }
        
        if(dp.count(val)) return dp[val];
         
        int action1 = val%2 + solve(val/2);
        
        int action2 = val%3  + solve(val/3);

        return dp[val] = 1 + min({action1, action2});
    }
    int minDays(int n) {
        dp.clear();
        return solve(n);
    }
};