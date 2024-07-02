class Solution {
public:
    void helper(string &s, int start, int last_remove, char open, char close, vector<string> &res) {
        for (int stack = 0, i = start; i < s.length(); ++i) {
            if (s[i] == open) stack++;
            if (s[i] == close) stack--;
            if (stack >= 0) continue;

            for (int j = last_remove; j <= i; ++j) {
                if (s[j] == close && (j == last_remove || s[j - 1] != close)) {
                    string curr = s.substr(0, j) + s.substr(j + 1);
                    helper(curr, i, j, open, close, res);
                }
            }
            return;
        }
        reverse(s.begin(), s.end());
        if (open == '(')
            helper(s, 0, 0, ')', '(', res);
        else
            res.push_back(s);
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, '(', ')', res);
        return res;
    }
};
