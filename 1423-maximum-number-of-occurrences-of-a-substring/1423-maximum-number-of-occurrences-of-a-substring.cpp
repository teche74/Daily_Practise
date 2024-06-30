class Solution {
public:
    int solve(string s, int maxLetters, int maxSize){
        int low = 0 , high = 0 , size = s.size() , res= 0;
        int map[26];
        int count_uni = 0;
        unordered_map<string,int>counter;

        memset(map,0,sizeof(map));

        while(high < size){
            map[s[high] - 'a']++;
            count_uni += (map[s[high] - 'a'] == 1);

            while(high - low + 1 > maxSize || count_uni > maxLetters){
                map[s[low] - 'a']--;
                count_uni -= (map[s[low] - 'a'] == 0);
                low++;
            }

            int len  = high - low +1;
            if(len == maxSize){
                string str = s.substr(low, len);
                counter[str]++;
                res = max(res,counter[str]);
            }

            high++;
        }

        return res;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0 ;

        for(int i =minSize ;i <=maxSize ; i++){
            res = max(res, solve(s,maxLetters,i));
        }

        return res;
    }
};