class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<string,pair<int,bool>>map;
        int low = 0, high = 0, size = s.size();
        vector<string> res;

        while(high < size){
            
            while(high - low + 1 >= 10){
                string str = s.substr(low, high - low+1);
                map[str].first++;

                if(map[str].first > 1 && map[str].second == false){
                    map[str].second = true;
                    res.emplace_back(str);
                }
                low++;
            }

            high++;
        } 
        return res;
    }
};