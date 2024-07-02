class Solution {
public:
    string removeOuterParentheses(string s) {
        int size = s.size();
        int balanced = 0, depth = 0;
        string res = "";

        for(char ch : s){
            if(ch == '('){

                if(depth > 0){
                    res.push_back(ch);
                }
                depth++;
            }
            else{
                depth--;

                if(depth > 0 ){
                    res.push_back(ch);
                }
            }
        }
        return res;
    }
};