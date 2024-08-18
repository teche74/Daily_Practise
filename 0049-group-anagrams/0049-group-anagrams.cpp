class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;

        for(const string  & str : strs){
            string ptr = str;

            sort(ptr.begin(), ptr.end());

            map[ptr].emplace_back(str);
        }

        vector<vector<string>>res;

        for(auto t : map){
            res.emplace_back(t.second);
        }

        return res;
    }
};