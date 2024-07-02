class Solution {
public:
    int scoreOfParentheses(string s) {
        int size = s.size();

        int paran = 0 , res = 0;

        for(int i =1; i < size ; i++){
            if(s[i] == '('){
                paran++;
            }
            else if(s[i-1] == '('){
                res += 1 << paran;
                paran--;
            }
            else{
                paran--;
            }
        }
        return res;
    }
};