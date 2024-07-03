class Solution {
public:
    void helper(string s, int start, int last_remove, char open, char close, vector<string> &res) {
        int balance = 0;
        for (int i = start; i < s.length(); ++i) {
            if (s[i] == open) balance++;
            if (s[i] == close) balance--;
            if (balance < 0) {
                for (int j = last_remove; j <= i; ++j) {
                    if (s[j] == close && (j == last_remove || s[j - 1] != close)) {
                        helper(s.substr(0, j) + s.substr(j + 1), i, j, open, close, res);
                    }
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        if (open == '(') {
            helper(s, 0, 0, ')', '(', res);
        } else {
            res.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        helper(s, 0, 0, '(', ')', res);
        return res;
    }
};