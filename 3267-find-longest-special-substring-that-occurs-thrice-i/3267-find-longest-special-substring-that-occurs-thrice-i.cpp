class Solution {
public:
    int maximumLength(string s) {
        int size = s.size();
        int res = -1;
        

        for (int len = 1; len <= size; ++len) {
            int low = 0, high = 0;
            unordered_map<char, int> map;
            unordered_map<string, int> counter;
            int maxFreq = 0;
            
            while (high < size) {
                map[s[high]]++;
                
                while (map.size() > 1 || (high - low + 1) > len) {
                    map[s[low]]--;
                    if (map[s[low]] == 0) map.erase(s[low]);
                    low++;
                }
                
                if (high - low + 1 == len && map.size() == 1) {
                    string t = s.substr(low,len);
                    counter[t]++;
                    maxFreq = max(maxFreq, counter[t]);
                }
                
                high++;
            }
            
            if (maxFreq >= 3) {
                res = max(res,len);
            }
        }
        
        return res;
    }
};
