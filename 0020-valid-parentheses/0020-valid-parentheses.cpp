class Solution {
public:
    bool isValid(string s) {
        
        function<bool(char , char)> check = [](char val1 , char val2){
            return (val1 == '('  && val2 == ')' || val1 == '[' && val2 ==']' || val1 == '{' && val2 =='}');  
        };


        stack<char>st;

        for(auto t : s){
            if(t =='(' || t =='[' || t =='{'){
                st.push(t);
            }
            else{
                if(st.empty() || !check(st.top(),t)) return false;
                else st.pop();
            }
        }

        return st.empty();
    }
};