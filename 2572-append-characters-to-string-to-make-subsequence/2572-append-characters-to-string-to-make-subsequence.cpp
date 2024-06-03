class Solution {
public:
    void solve(int i, int j, const string &s, const string &t, int &count) {
        if (j == t.size()) {
            count = 0;
            return;
        }
        if (i == s.size()) {
            count = t.size() - j;
            return;
        }

        if (s[i] == t[j]) {
            solve(i + 1, j + 1, s, t, count);
        } else {
            int tempCount = INT_MAX;
            solve(i + 1, j, s, t, tempCount);
            count = min(count, tempCount);
        }
    }

    int appendCharacters(string s, string t) {
        int count = INT_MAX;
        solve(0, 0, s, t, count);
        return count;
    }
};
