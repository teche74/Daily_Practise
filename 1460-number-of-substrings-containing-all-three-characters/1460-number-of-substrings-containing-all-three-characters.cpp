class Solution {
public:
    int numberOfSubstrings(string s) {
        int low = 0 , high = 0 ,size = s.size() , res= 0 ;
        int count[3], all_3 = 0;
        memset(count,0, sizeof(count));

        while(high < size){
            count[s[high] - 'a']++;
            all_3 +=(count[s[high] - 'a'] == 1);

            while(all_3 >= 3){
                res +=size - high;
                count[s[low] - 'a']--;
                all_3 -= (count[s[low] - 'a'] == 0);
                low++;
            }
            high++;
        }

        return res;
    }
};