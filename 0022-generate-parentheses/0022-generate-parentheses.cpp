class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;  
        string temp;

        function<void(int,int)> check = [&](int open ,  int close){
            if(!open && !close){
                res.push_back(temp);
                return;
            }

            if(open){
                temp.push_back('(');
                check(open-1 , close);
                temp.pop_back();
            }
            if(close){
                if(open < close){
                    temp.push_back(')');
                    check(open , close-1);
                    temp.pop_back();
                }
            }
        };

        check(n,n);

        return res;
    }
};