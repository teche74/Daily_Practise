class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> map;
        
        for (const auto& item : items1) {
            int value = item[0];
            int weight = item[1];
            map[value] += weight;
        }
        
        for (const auto& item : items2) {
            int value = item[0];
            int weight = item[1];
            map[value] += weight;
        }
        
        vector<vector<int>> result;
        for (const auto& pair : map) {
            result.push_back({pair.first, pair.second});
        }
        
        sort(result.begin(), result.end());
        
        return result;
    }
};
