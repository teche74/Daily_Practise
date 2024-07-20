class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int low =0 , high = 0 , size = s.size() , res = 0 ;
        int pair = 0;

        while(high < size){
            if(high > 0 && s[high] == s[high -1]){
                pair++;
            }

            while(pair > 1){
                low++;
                if(low > 0 && s[low] == s[low-1]){
                    pair--;
                }
            }

            if(pair <= 1 ) res = max(res, high - low+1);
            high++;
        }

        return res;
    }
};