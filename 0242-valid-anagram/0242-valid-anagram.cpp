class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;

        for(auto t : s){
            map[t]++;
        }

        int high = 0 , size = t.size();

        while(high < size){
            if(map.find(t[high]) == map.end() || map[t[high]] == 0 ) return false;

            map[t[high]]--;
            if(map[t[high]] == 0) map.erase(t[high]);
            high++;
        } 

        return map.empty();
    }
};