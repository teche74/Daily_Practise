class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0, high = 0 , size = s.size(), maxi = 0;

        unordered_map<char,int>map;

        while(high < size){
            map[s[high]]++;

            while(map[s[high]] >= 2){
                map[s[low++]]--;
            }

            maxi = max( maxi, high - low+1);
            high++;
        }

        return maxi;
    }
};