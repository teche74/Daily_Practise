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
                reverse(s.begin() + paran.top() + 1, s.begin() + i);
                paran.pop();
            }
        }

        s.erase(remove(s.begin(), s.end(), '('), s.end());
        s.erase(remove(s.begin(), s.end(), ')'), s.end());

        return s;
    }
};