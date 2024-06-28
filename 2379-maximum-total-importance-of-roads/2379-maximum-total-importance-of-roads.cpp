class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        
        for (auto& r : roads) {
            deg[r[0]]++;
            deg[r[1]]++;
        }
        
        vector<pair<int, int>> degCity;
        for (int i = 0; i < n; ++i) {
            degCity.emplace_back(deg[i], i);
        }
        sort(degCity.begin(), degCity.end(), greater<>());
    
        vector<int> val(n);
        for (int i = 0; i < n; ++i) {
            val[degCity[i].second] = n - i;
        }
        
        long long res = 0;
        for (auto& r : roads) {
            res += val[r[0]] + val[r[1]];
        }
        
        return res;
    }
};
