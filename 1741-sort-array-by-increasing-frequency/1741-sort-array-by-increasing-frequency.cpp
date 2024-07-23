class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>map;

        for(auto t : nums){
            map[t]++;
        }

        vector<pair<int,int>> pairs;

        for(auto t : map){
            pairs.push_back({t.second,t.first});
        }

        sort(pairs.begin(),pairs.end() , [&](const pair<int,int> & a, const pair<int,int> & b){
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        });

        vector<int>res;

        for(auto t : pairs){
            while(t.first--){
                res.emplace_back(t.second);
            }
        }
        return res;
    }
};