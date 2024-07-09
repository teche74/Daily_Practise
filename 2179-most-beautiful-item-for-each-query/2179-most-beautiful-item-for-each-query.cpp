class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int>res;

        sort(items.begin(),items.end());

        vector<int> pre(items.size());
        pre[0] = items[0][1];
        for (int i = 1; i < items.size(); ++i) {
            pre[i] = max(pre[i - 1], items[i][1]);
        }

        for(auto x : queries){
            int low = 0 , high = items.size()-1;
            int ans = -1;

            while(low <= high){
                int mid = low + (high - low)/2;


                if(items[mid][0] <= x){
                    ans = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            if(ans >= 0 && ans < items.size())
                res.emplace_back(pre[ans]);
            else
                res.emplace_back(0);
        }
        return res;
    }
};