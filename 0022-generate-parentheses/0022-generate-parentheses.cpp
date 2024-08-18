class Solution {
public:
    void solve(int open , int close ,  string temp  , vector<string> & res){
        if(open == 0 && close == 0){
            res.emplace_back(temp);
            return ;
        }

        if(open > 0){
            temp.push_back('(');
            solve(open-1, close, temp,res);
            temp.pop_back();
        }

        if(close > 0){
            if(close > open){
                temp.push_back(')');
                solve(open, close -1 , temp,res);
                temp.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp =  "";

        solve(n,n, temp,res);
        return res;
    }
};