class Solution {
public:
    unordered_map<string,bool> map;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        if(s1.size() != s2.size()) return false;

        int size = s1.size();

        string key = s1 + '.' + s2;

        if(map.count(key)) return map[key];

        for(int i =1; i < size; i++)
        {
            if(isScramble(s1.substr(0, i) , s2.substr( size-i, i)) && isScramble(s1.substr(i, size- i) , s2.substr(0, size-i))){
                map[key] = true;
                return true;
            }

            if(isScramble(s1.substr(0, i) , s2.substr(0, i)) && isScramble(s1.substr(i, size- i) , s2.substr(i, size-i))){
                map[key] = true;
                return true;
            }
        }

        map[key] = false;
        return map[key];
    }
};