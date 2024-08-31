class Solution {
public:
    int dp[1001];

    bool solve(int val , int alice){
        if(val <= 1 ){
            return false;
        }

        if(dp[val] != -1) return dp[val];

        bool t = false;

        for(int  i = 1 ; i < val ; i++){
            if(val % i == 0 && !solve(val - i , abs(alice -1))){
                t =  true;
                break;
            }
        }
        return dp[val] = t;
    }
    bool divisorGame(int n) {
        memset(dp, -1 , sizeof(dp));
        int alice = 1;
        return solve(n ,alice);
    }
};