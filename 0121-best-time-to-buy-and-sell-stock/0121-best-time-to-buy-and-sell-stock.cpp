class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0] ,res = 0;

        int size = prices.size();

        for(int i = 0; i < size ; i++){
            mini = min(mini,prices[i]);

            res = max(res, prices[i] - mini);
        } 

        return res;
    }
};