class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        if (words.empty()) return {};
        
        vector<int> count(26, 0); 
        for (char c : words[0]) {
            count[c - 'a']++;
        }
        
        for (int i = 1; i < words.size(); ++i) {
            vector<int> temp(26, 0);
            for (char c : words[i]) {
                temp[c - 'a']++;
            }
            
            for (int j = 0; j < 26; ++j) {
                count[j] = min(count[j], temp[j]);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            while (count[i]-- > 0) {
                res.push_back(string(1, i + 'a'));
            }
        }
        
        return res;
    }
};