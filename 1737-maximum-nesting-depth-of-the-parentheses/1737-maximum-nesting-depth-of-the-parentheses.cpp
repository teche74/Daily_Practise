class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int res = 0;

        for(char ch : s){
            if(ch == '('){
                st.push(ch);
                res = max(res, static_cast<int>(st.size()));
            }
            else if(ch == ')'){
                st.pop();
            }
        }
        return res;
    }
};