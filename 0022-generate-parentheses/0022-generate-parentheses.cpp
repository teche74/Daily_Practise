class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;

        function<void(int,int,string)> generate = [&](int open,int close, string temp){
            if(open == 0 and close == 0){
                res.emplace_back(temp);
                return ;
            }

            if(open > 0){
                temp.push_back('(');
                generate(open-1,close,temp);
                temp.pop_back();
            }

            if(close > 0){
                if(close > open){
                    temp.push_back(')');
                    generate(open, close-1,temp);
                    temp.pop_back();
                }
            }
        };

        generate(n,n,"");


        return res;

    }
};