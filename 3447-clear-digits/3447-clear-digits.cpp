class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;

        for(char ch : s){
            if(isdigit(ch)){
                if(st.empty()) break;
                else st.pop();
            }
            else{
                st.push(ch);
            }
        }

        string res(st.size(),'.');
        int size = st.size();
        for(int i = size-1; i>= 0; i--){
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};