class Solution {
public:
    void solve(int index, const string &s, string temp, vector<string> &res, int count) {
        if (count == 4) {
            if (index == s.size()) {
                res.push_back(temp);
            }
            return;
        }

        int num = 0;
        for (int i = index; i < s.size(); i++) {
            num = num * 10 + (s[i] - '0');
            if (num <= 255) {
                if (i > index && s[index] == '0')  
                    break;
                string segment = to_string(num);
                if (count < 3)
                    segment.push_back('.');
                solve(i + 1, s, temp + segment, res, count + 1);
            } else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        solve(0, s, "", res, 0);
        return res;
    }
};