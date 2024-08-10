class Solution {
public:
    string longestNiceSubstring(string s) {
        int max_len = 0;
        string res = "";

        for (int i = 0; i < s.size(); ++i) {
            vector<pair<bool, bool>> map(26, {false, false});
            for (int j = i; j < s.size(); ++j) {
                if (islower(s[j])) {
                    map[s[j] - 'a'].first = true;
                } else {
                    map[tolower(s[j]) - 'a'].second = true;
                }

                bool nice = true;
                for (int k = 0; k < 26; ++k) {
                    if (map[k].first != map[k].second) {
                        nice = false;
                        break;
                    }
                }

                if (nice && (j - i + 1) > max_len) {
                    max_len = j - i + 1;
                    res = s.substr(i, max_len);
                }
            }
        }

        return res;
    }
};
