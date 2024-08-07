class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,pair<int,bool>>map;
        int low = 0, high = 0, size = s.size();
        vector<string> res;

        while(high < size){
            
            while(high - low + 1 >= 11){
                low++;
            }

            if(high - low +1 == 10){
                string str = s.substr(low, high - low+1);
                map[str].first++;

                if(map[str].first > 1){
                    if(map[str].first > 1 && map[str].second == false){
                        map[str].second = true;
                        res.emplace_back(str);
                    }
                }
            }
            high++;
        } 
        return res;
    }
};