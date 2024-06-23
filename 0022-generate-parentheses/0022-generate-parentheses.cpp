class Solution {
public:
    void solve(int open, int close, string temp, vector<string> & res){
        if(!open  && !close){
            res.emplace_back(temp);
            return;
        }

        if(open){
            temp.push_back('(');
            solve(open-1, close, temp,res);
            temp.pop_back();
        }

        if(close){
            if(close > open){
                temp.push_back(')');
                solve(open, close-1, temp,res);
                temp.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        int open{n}, close{n};

        vector<string>res;
        string temp = "";
        
        solve(open , close, temp,res);

        return res;
    }
};