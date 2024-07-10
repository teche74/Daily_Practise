class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        vector<pair<int, int>> count;
        for (const auto& entry : frequency) {
            count.emplace_back(entry.second, entry.first);
        }

        sort(count.rbegin(), count.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(count[i].second); 
        }

        return res;
    }
};