class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>not_balance;

        stack<int>st;

        int size = s.size();

        for(int i = 0 ; i < size ; i++ ){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    not_balance.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        while(st.size()){
            not_balance.insert(st.top());
            st.pop();
        }

        string res = "";

        for(int i = 0; i <s.size() ; i++){
            if(not_balance.find(i) == not_balance.end()){
                res.push_back(s[i]);
            }
        }

        return res;

    }
};