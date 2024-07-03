class Solution {
public:
    int scoreOfParentheses(string s) {
        int size  = s.size();

        int open  = 0 , res = 0;

        for(int i = 1; i < size ; i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i-1] == '('){
                res += 1 << open;
                open--;
            }
            else{
                open--;
            }
        }
        return res;
    }
};