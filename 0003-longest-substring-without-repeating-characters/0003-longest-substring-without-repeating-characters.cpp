class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256];
        memset(freq, -1, sizeof(freq));

        int low=  0 , high= 0 , size = s.size(), res = 0;

        for(high = 0 ; high < size ; high++){
            low = max(low,freq[s[high]]+1);
            res = max(res , high - low+1 );
            freq[s[high]] = high; 
        } 

        return res;
    }
};