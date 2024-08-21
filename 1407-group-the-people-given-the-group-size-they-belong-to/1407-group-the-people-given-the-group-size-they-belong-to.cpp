class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<vector<int>>>map;

        int size = groupSizes.size();

        for(int i = 0  ; i < size ; i++){
            if(map[groupSizes[i]].empty() || map[groupSizes[i]].back().size() == groupSizes[i]){
                map[groupSizes[i]].emplace_back(vector<int>{i});
            }
            else{
                map[groupSizes[i]].back().emplace_back(i);
            }
        }

        vector<vector<int>>res;

        for(auto t : map){
            for(vector<int> x : t.second)
                res.emplace_back(x);
        }

        return res;
    }
};