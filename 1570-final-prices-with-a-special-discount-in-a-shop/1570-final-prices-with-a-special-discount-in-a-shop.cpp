class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>res;
        for(int  i =0; i < prices.size() ; i++){
            int j = i+1;

            while(j < prices.size() && prices[i] < prices[j] ) j++;

            res.emplace_back( (j == prices.size() ? prices[i] : prices[i] - prices[j]));
        }
        return res;
    }
};