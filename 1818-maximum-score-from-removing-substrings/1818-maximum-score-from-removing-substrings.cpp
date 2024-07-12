class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int size = s.size();

        auto solve = [&](string &s, char first, char second, int points) {
            string newStr;
            int score = 0;
            for (char c : s) {
                if (!newStr.empty() && newStr.back() == first && c == second) {
                    newStr.pop_back();
                    score += points;
                } else {
                    newStr.push_back(c);
                }
            }
            s = newStr;
            return score;
        };
        
        return x > y ? solve(s,'a','b',x) + solve(s,'b','a',y) : solve(s,'b','a',y) + solve(s,'a','b',x); 
    }
};