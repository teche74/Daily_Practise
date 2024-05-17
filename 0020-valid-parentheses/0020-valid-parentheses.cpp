class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        auto isopen = [](char ch)->bool{
            return ch == '(' || ch == '[' || ch == '{';
        };

        auto match = [](char ch , char ch2)->bool{
            if(ch == '(' && ch2 == ')') return true;
            if(ch == '[' && ch2 == ']') return true;
            if(ch == '{' && ch2 == '}') return true;
            return false; 
        }; 

         for (char ch : s) {
            if (isopen(ch)) {
                st.push(ch);
            } else {
                if (st.empty() || !match(st.top(), ch)) {
                    return false;
                }
                st.pop();
            }
        }

        return st.empty();
    }
};