class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0 , high = 0 , size = s.size() , res = 0 ;

        unordered_map<int,int>map;


        while( high < size) {
            map[s[high] - 'a']++;

            while(map[s[high]-'a'] > 1){
                map[s[low] - 'a']--;
                low++;
            }

            res = max(res, high - low+1);
            high++;
        }
        return res;
    }
};