class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        unordered_map<string,vector<string>>map;

        for(const string & str  : strs){
            string t = str;

            sort(t.begin(),t.end());

            map[t].emplace_back(str);
        }

        for(auto t  : map){
            res.emplace_back(t.second);
        }

        return res;
    }
};