class Solution {
public:
    int longestValidParentheses(string s) {
        int size = s.size() , res = 0;
        stack<int>st;
        st.push(-1);

        for(int i = 0 ;i  < size; i++){
            if(s[i] == '('){
                st.push(i);
            } 
            else{
                if(st.size() == 1){
                    st.top() = i;
                }
                else{
                    st.pop();
                }
                res = max(res , i - st.top());
            }
        }

        return res;
    }
};