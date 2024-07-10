class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256];

        memset(map, -1,sizeof(map));

        int low = 0 , high = 0 , size = s.size() ,res= 0;

        for(high = 0 ; high < size ; high++){
            low = max(low , map[s[high]]+1);
            res = max(res, high - low +1);
            map[s[high]] = high; 
        }
        return res;
    }
};