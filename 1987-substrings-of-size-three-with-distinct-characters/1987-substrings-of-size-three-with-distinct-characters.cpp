class Solution {
public:
    int countGoodSubstrings(string s) {
        int low = 0 , high = 0 , size = s.size() , res = 0 ;
        int freq[26] = {0};

        while( high  < size){
            freq[s[high] - 'a']++;

            while(freq[s[high] - 'a'] > 1){
                freq[s[low] - 'a']--;
                low++;
            }

            res += (high - low + 1 == 3);
            high++;
        } 

        return res;
    }
};