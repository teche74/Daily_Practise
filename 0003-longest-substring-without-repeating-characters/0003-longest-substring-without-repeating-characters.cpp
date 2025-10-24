class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[257];
        memset(alpha , 0 , sizeof(alpha));

        int size = s.size() , low = 0 ,high = 0 , res = 0;

        while(high < size){
            alpha[s[high]]++;

            while(alpha[s[high]] > 1){
                alpha[s[low]]--;
                low++;
            }
            res = max(res , high - low + 1);
            high++;
        }

        return res;
    }
};