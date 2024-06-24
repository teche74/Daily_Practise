class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        unordered_map<string,vector<string>>map;

        for(auto t : strs){
            string temp = t;
            sort(t.begin(),t.end());

            map[t].emplace_back(temp);
        }

        for(auto t : map){
            res.emplace_back(t.second);
        }

        return res;
    }
};