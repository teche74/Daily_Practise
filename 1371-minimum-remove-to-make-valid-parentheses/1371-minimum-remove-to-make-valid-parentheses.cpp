class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int>indices;

        stack<int>st;
        int size = s.size();

        for(int i =0 ;i < size; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    indices.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }

        while(st.size()){
            indices.insert(st.top());
            st.pop();
        }

        string res = "";

        for(int i =0; i <size ;i++){
            if(indices.find(i) == indices.end()){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};