class Solution {
public:
    int scoreOfParentheses(string s) {
        int size  = s.size();

        int open  = 0 , res = 0;

        for(int i = 1; i < size ; i++){
            if(s[i] == '('){
                open++; // open brackets ka occurence count kr le 
            }
            else if(s[i-1] == '('){
                res += 1 << open; // closing bracket hit hone prr jitne open brackets he unpe multiplicative property.
                open--;
            }
            else{
                // otherwise open count decrease krte rho
                open--;
            }
        }
        return res;
    }
};