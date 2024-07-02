class Solution {
public:
    void removeInvalidParenthesesHelper(string &s, int start, int lastRemove, char openParen, char closeParen, vector<string> &res) {
        for (int stack = 0, i = start; i < s.length(); ++i) {
            if (s[i] == openParen) stack++;
            if (s[i] == closeParen) stack--;
            if (stack >= 0) continue;

            for (int j = lastRemove; j <= i; ++j) {
                if (s[j] == closeParen && (j == lastRemove || s[j - 1] != closeParen)) {
                    string curr = s.substr(0, j) + s.substr(j + 1);
                    removeInvalidParenthesesHelper(curr, i, j, openParen, closeParen, res);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (openParen == '(')
            removeInvalidParenthesesHelper(s, 0, 0, ')', '(', res);
        else
            res.push_back(s);
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        removeInvalidParenthesesHelper(s, 0, 0, '(', ')', res);
        return res;
    }
};
