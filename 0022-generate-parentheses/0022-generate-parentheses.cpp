class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp;

        function<void(int,int)> call = [&](int open , int close){
            if(!open && !close){
                res.push_back(temp);
                return;
            }

            if(open){
                temp.push_back('(');
                call(open-1 , close);
                temp.pop_back();
            }
            if(close && close > open){
                temp.push_back(')');
                call(open, close-1);
                temp.pop_back();
            }
        };

        call(n,n);
        return res;
    }
};