class Solution {
public:
    unordered_map<string,bool>map;

    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;

        if(s1.length() != s2.length())  return false;

        string helper = s1 + '$' + s2;

        if(map.count(helper)) return map[helper];

        int size =  s1.size();

        for(int i =1 ; i < size ; i++){
            if(isScramble(s1.substr(0, i) ,s2.substr(size - i , i) ) && isScramble(s1.substr(i,size - i) , s2.substr(0, size - i)) ) {
                map[helper] = true;
                return true;   
            }
            if(isScramble(s1.substr(0, i) , s2.substr(0, i)) && isScramble(s1.substr(i, size - i), s2.substr( i , size - i ))   ) {
                map[helper] = true;
                return true;
            }
        }  

        map[helper] = false;

        return map[helper];
    }
};