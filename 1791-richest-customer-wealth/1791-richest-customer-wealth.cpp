class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;

        for(auto t : accounts){
            res = max(res, accumulate(t.begin(),t.end(),0));
        }
        
        return res;
    }
};