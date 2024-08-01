class Solution {
public:
    unordered_map<string,bool>dp;
    bool solve(int val , int turn){
        if(val == 1 ){
            return false;
        }

        string key = to_string(val) + to_string(turn);

        if(dp.count(key)) return dp[key];

        int pos = false;
        for(int i = 1; i < val ;i++){
            if(val % i == 0 ){
                if(!solve(val-i,abs(turn-1))){
                    pos = true;
                    break;
                }
            }
        }

        return dp[key] = pos;
    }
    bool divisorGame(int n) {
        int turn =1;
        return solve(n, turn);
    }
};