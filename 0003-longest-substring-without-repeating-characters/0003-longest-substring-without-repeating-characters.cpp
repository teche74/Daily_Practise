class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[256];
        memset(map, -1, sizeof(map));

        int low = 0 , high = 0 , size = s.size(), res = 0;

        while(high < size){
            low = max(low , map[s[high]]+1);
            res = max(res, high - low+1);
            map[s[high]] = high; 
            high++;
        }

        return res;
    }
};