class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char>st;

        for(char ch : s){
            st.push(ch);
        }

        for(int  i =t.size()-1 ;i>=0 ;i--){
            if(!st.empty() && t[i] == st.top()){
                st.pop();
            }
        }

        return st.empty();
    }
};