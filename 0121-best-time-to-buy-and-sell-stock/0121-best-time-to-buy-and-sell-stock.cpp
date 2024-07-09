class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size =prices.size();
        int prev = prices[0], res = 0;

        for(int i =1; i < size ; i++){
            prev = min(prev, prices[i]);
            res = max(res, prices[i] - prev);
        }

        return res;
    }
};