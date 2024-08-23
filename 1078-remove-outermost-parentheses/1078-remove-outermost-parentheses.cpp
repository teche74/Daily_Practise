class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        int size = s.size();
        string res = "";

        for(int  i = 0; i < size ; i++){
            if(s[i] == '(' ){
                open++;
                if(open > 1){
                    res.push_back(s[i]);
                }
            }
            else{
                if(open > 1){
                    res.push_back(s[i]);
                }
                open--;
            }
        }
        return res;
    }
};