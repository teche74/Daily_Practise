class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for(char ch : s){
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string res = string(st.size(), '.');
        int size = st.size();

        for(int i = size-1; i>= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};