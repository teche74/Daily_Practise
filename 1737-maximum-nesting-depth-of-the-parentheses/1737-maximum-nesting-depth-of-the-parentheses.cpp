class Solution {
public:
    int maxDepth(string s) {
        int open  = 0, res = 0 ;

        for(auto t : s){
            if(t == '('){
                open++;
            }
            else if(t ==')'){
                res = max(res, open);
                open--;
            }
        }
        return res;
    }
};