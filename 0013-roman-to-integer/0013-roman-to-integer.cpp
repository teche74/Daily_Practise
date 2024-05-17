class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int val = map[s[0]];

        for(int i =1 ; i < s.size(); i++){
            if(map[s[i]] > map[s[i-1]]){
                val+= (map[s[i]] ) - (2 *map[s[i-1]]);
            }
            else{
                val+=map[s[i]];
            }
        }

        return val;
    }
};