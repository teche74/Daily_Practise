class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";

        int size = s.size();

        for(int i =0 ; i < size; i++){
            if(s[i] == '('){
                int j = i+1;
                int count  =1;

                while(j < size && count != 0){
                    count += (s[j] == '(') ? 1 :-1;
                    if(count) res.push_back(s[j]);
                    j++; 
                }
                i = j-1;
            }
        }

        return res;
    }
};