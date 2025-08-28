class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,pair<int,bool>>map;
        vector<string>res;
        int  size = s.size();

        for(int i = 0 ; i <= size-10 ; i++){
            string str = s.substr(i, 10);

            if(map[str].second == true) continue;
            map[str].first++;

            if(map[str].first > 1){
                map[str].second = true;
                res.push_back(str);
            }
        }

        return res;
    }
};