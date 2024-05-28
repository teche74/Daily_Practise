class Solution {
public:

    bool Palli(const string & s, int low, int high){
        while(low<high){
            if(s[low]!=s[high]) return false;
            low++;
            high--;
        }
        return true;
    }

    int solve(const string  & s, int low,  int high, vector<vector<int>> & dp){
        if(dp[low][high] != -1) return dp[low][high];
        if(Palli(s,low,high)) {
            dp[low][high] = 0;
            return 0;
        }

        int cuts = INT_MAX;
        for(int i = low ; i< high ; i++){
            if(Palli(s,low,i)){
                cuts  =min(1+solve(s,i+1,high,dp),cuts);
            }
        }

        dp[low][high] = cuts;
        return dp[low][high];
    }

    int minCut(string s) {
        int size = s.size();
        vector<vector<int>>dp(size,vector<int>(size,-1));
        return solve(s,0 ,size-1,dp);
    }
};