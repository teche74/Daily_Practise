class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int low = 0 , high = 0 , size = s.size() , res= 0;
        int map[26];
        int count_uni = 0;

        unordered_map<string,int>counter;
        memset(map,0,sizeof(map));

        while(high < size){
            map[s[high] - 'a']++;
            count_uni += (map[s[high] - 'a'] == 1);

            if(count_uni <= maxLetters && high - low +1 >= minSize){
                string t = s.substr(low, high - low+1);
                counter[t]++;
                res = max(res,counter[t]);
            }

            while(high - low + 1 >= minSize ){
                map[s[low] - 'a']--;
                count_uni -= (map[s[low] - 'a'] == 0);
                low++;
            }
            high++;
        }

        return res;
    }
};