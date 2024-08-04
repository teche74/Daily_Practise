class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        for(char ch : s){
            if(ch == '*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(ch);
            }
        }

        // string res = "";

        // while(!st.empty()){
        //     res.push_back(st.top());
        //     st.pop();
        // }

        // reverse(res.begin(),res.end());
        // return res;

        int size = st.size();
        string res(size,'.');

        for(int i = size-1 ; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};