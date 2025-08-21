class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long res = 0 , sum = 0;
        int low = 0, high = 0 , size = prices.size();

        vector<long long>temp , price_sum , contri;
        for(int i = 0 ; i < size; i++){
            temp.push_back(1LL * prices[i] * strategy[i]);
            price_sum.push_back(1LL * prices[i] + (i > 0  ? price_sum[i-1] : 0));
            contri.push_back(1LL * temp[i] + (i > 0 ? contri[i-1] : 0)); 
        }

        res = contri.back();
        long long original_sum = res;

        while(high < size){
            while(high - low + 1 >= k){
                sum  = original_sum - (contri[high] - (low > 0 ? contri[low-1] : 0)) + (price_sum[high] - price_sum[(low + (k/2)-1)]);
                res = max(res , sum);
                low++;
            }
            high++;
        }

        return res;
    }
};