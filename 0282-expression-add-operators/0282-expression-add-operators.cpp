class Solution {
public:
    void solve(vector<string>& res, const string& num, int target, long long diff, long long curNum, string expr, int pos) {
        if (pos == num.size()) {
            if (curNum == target) {
                res.push_back(expr);
            }
            return;
        }
        
        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;  
            
            string part = num.substr(pos, i - pos + 1);
            long long current = stoll(part);
            
            if (pos == 0) {
                solve(res, num, target, current, current, part, i + 1);
            } else {
                solve(res, num, target, current, curNum + current, expr + "+" + part, i + 1);
                solve(res, num, target, -current, curNum - current, expr + "-" + part, i + 1);
                solve(res, num, target, diff * current, curNum - diff + diff * current, expr + "*" + part, i + 1);
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        solve(res, num, target, 0, 0, "", 0);
        return res;
    }
};