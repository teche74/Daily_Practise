class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>map;

        for(string str : strs){
            string temp_str = str;
            sort(str.begin() , str.end());
            map[str].push_back(temp_str);
        }

        for(auto entry : map){
            res.push_back(entry.second);
        }

        return res;
    }
};