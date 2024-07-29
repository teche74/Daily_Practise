class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;

        unordered_map<string,vector<string>>store;

        for(auto t : strs){
            string str = t;

            sort(t.begin(),t.end());

            store[t].emplace_back(str);
        }

        for(auto t : store){
            res.emplace_back(t.second);
        }

        return res;
    }
};