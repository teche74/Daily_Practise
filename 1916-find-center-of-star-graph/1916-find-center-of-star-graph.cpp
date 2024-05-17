class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>map;

        for(auto t : edges){
            map[t[0]].emplace_back(t[1]);
            map[t[1]].push_back(t[0]);
        }

        for(auto t : map){
            if(t.second.size() == edges.size()){
                return t.first;
            }
        }

        return -1;
    }
};