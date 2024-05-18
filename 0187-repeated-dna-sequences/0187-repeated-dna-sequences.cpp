class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};

        unordered_map<string,int>map;

        for(int i =0 ; i <= s.size()-10 ; i++){
            string temp= s.substr(i, 10);

            map[temp]++;
        }

        vector<string>res;

        for(auto it : map){
            if(it.second >= 2){
                res.emplace_back(it.first);
            }
        }
        return res;
    }
};