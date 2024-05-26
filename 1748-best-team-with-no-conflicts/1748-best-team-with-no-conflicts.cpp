class Solution {
public:
int dp[1006];
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int size = scores.size();

        vector<pair<int,int>>pairs;

        for(int i =0; i <size ; i++){
            pairs.emplace_back(ages[i],scores[i]);
        }

        sort(pairs.begin(),pairs.end());

    
        int res = 0;

        for (int i = 0; i < size; ++i) {
            dp[i] = pairs[i].second;
            
            for (int j = 0; j < i; ++j) {
                if (pairs[j].second <= pairs[i].second) {
                    dp[i] = max(dp[i], dp[j] + pairs[i].second);
                }
            }
            res = max(res, dp[i]);
        }


        return res;

    }
};