class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> paran;
        int size = s.size();

        for(int i = 0; i < size; i++){
            if(s[i] == '('){
                paran.push(i);
            }
            else if(s[i] == ')'){
                std::reverse(s.begin() + paran.top() + 1, s.begin() + i);
                paran.pop();
            }
        }

        s.erase(std::remove(s.begin(), s.end(), '('), s.end());
        s.erase(std::remove(s.begin(), s.end(), ')'), s.end());

        return s;
    }
};