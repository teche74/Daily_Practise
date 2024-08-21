class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';  
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            if (!isdigit(ch) && !isspace(ch) || i == n - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (sign == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / num);
                }
                sign = ch;  
                num = 0;    
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};