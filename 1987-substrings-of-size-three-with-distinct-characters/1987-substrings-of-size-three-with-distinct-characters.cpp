class Solution {
public:
    int countGoodSubstrings(string s) {
        int low = 0 , high = 0 , size = s.size();
        int uni = 0, res= 0 ;
        int freq[26];
        memset(freq,0,sizeof(freq));

        while(high < size){
            freq[s[high] - 'a']++;
            uni  += (freq[s[high] - 'a'] == 1);

            while(uni > 3 || high - low+1 > 3){
                freq[s[low] - 'a']--;
                uni -= (freq[s[low]- 'a'] == 0);
                low++;
            }

            if(uni == 3) res++;
            high++;
        }
        return res;
    }
};