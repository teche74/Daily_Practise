class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0 , high =  0 , size = s.size(), res = 0;

        int occur[128];

        memset(occur, -1, sizeof(occur));

        for(int high = 0; high < size; high++){
            low = max(low, occur[s[high]]+1);
            res = max(res, high - low+1);
            occur[s[high]] = high;
        }

        return res;
    }
};