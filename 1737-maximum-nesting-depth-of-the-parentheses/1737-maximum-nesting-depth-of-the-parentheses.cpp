class Solution {
public:
    int maxDepth(string s) {
        int size = s.size();

        int open = 0, res = 0;

        for(int i =0; i < size ; i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                res = max(res, open);
                open--;
            }
        }

        return res;
    }
};