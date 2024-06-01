class Solution {
public:
    bool MatchPattern(string& query, string& pattern) {
        int i = 0, j = 0;
        while (i < query.size() && j < pattern.size()) {
            if (query[i] == pattern[j]) {
                j++;
            } else if (isupper(query[i])) {
                return false;
            }
            i++;
        }
        while (i < query.size()) {
            if (isupper(query[i]))
                return false;
            i++;
        }
        return j == pattern.size();
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string& query : queries) {
            res.push_back(MatchPattern(query, pattern));
        }
        return res;
    }
};