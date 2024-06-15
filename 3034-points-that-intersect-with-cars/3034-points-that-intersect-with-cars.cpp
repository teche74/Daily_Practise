class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        unordered_set<int> cover;
        
        for (const auto& t : nums) {
        
            
            for (int i = t[0]; i <= t[1]; i++) {
                cover.insert(i);
            }
        }
        
        return cover.size();
    }
};