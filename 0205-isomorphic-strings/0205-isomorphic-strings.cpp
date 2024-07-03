class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map1, map2;

        if(s.size() != t.size()) return false;
        
        int size = s.size();

        for(int i = 0 ; i < size ; i++){
            if(map1.find(s[i]) == map1.end()){
                map1[s[i]]  = t[i];
                if(map2.find(t[i]) != map2.end()) return false;
                map2[t[i]] = s[i];
            }
            else{
                if(t[i] != map1[s[i]] || s[i] != map2[t[i]]) return false;
            }
        }

        return true;
    }
};