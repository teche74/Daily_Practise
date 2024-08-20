class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;

        stack<int>st;

        for(auto t :  tokens){
            if(t == "+" || t == "-" || t =="*" || t =="/" ){
                int val2 = st.top();st.pop();
                int val = st.top();st.pop();
                if(t == "+")
                    st.push(val + val2);
                else if(t == "-")
                    st.push(val - val2);
                else if(t == "*")
                    st.push(val * val2);
                else
                    st.push(val / val2);
            }
            else{
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};