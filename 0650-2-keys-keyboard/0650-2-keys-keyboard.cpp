class Solution {
public:
    unordered_map<int, int> dp;
    
    int solve(int n){
        if(n == 1) return 0;
        if(dp.find(n) != dp.end()) return dp[n];
        
        int min_steps = n;
        for(int i = 2; i <= sqrt(n); ++i){
            if(n % i == 0){
                int j = n / i;
                min_steps = min(min_steps, solve(i) + j);
                min_steps = min(min_steps, solve(j) + i);
            }
        }
        dp[n] = min_steps;
        return min_steps;
    }
    
    int minSteps(int n) {
        return solve(n);
    }
};
