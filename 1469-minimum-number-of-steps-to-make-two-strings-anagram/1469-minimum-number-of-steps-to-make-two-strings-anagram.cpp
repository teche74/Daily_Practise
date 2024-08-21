class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>map;

        for(auto ch : s){
            map[ch]++;
        }

        for(auto ch : t){
            map[ch]--;
        }

        int diff = 0;

        for(auto t : map){
            if(t.second > 0)
                diff += t.second;
        }

        return diff;
    }
};