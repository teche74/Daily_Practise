class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp = "";

        function<void(int,int)> solve = [&](int open, int close)
        {
            if(open == 0 && close == 0){
                res.emplace_back(temp);
                return;
            }

            if(open > 0){
                temp.push_back('(');
                solve(open-1,close);
                temp.pop_back();
            }
            
            if(close > 0){
                if(close > open){
                    temp.push_back(')');
                    solve(open,close-1);
                    temp.pop_back();
                }
            }

        };

        solve(n,n);

        return res;
    }
};