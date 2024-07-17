class Solution {
public:
    unordered_map<string,bool>dp;
    int solve(int curr, int turn){
        if(curr == 1){
            return false;
        }

        string key = to_string(curr) + "-" + to_string(turn);
        if(dp.count(key)){
            return dp[key]; 
        }

        bool val1 = false;

        for(int i = 1 ; i <curr; i++){
            if(curr % i == 0){
                if(!solve(curr -i , abs(turn - 1) )) {
                    val1 = true;
                    break;
                }
            }
        }

        return dp[key] = val1;
    }
    bool divisorGame(int n) {
        return solve(n, 1);
    }
};