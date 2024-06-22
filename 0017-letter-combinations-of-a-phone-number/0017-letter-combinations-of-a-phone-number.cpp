class Solution {
public:
    void solve(int index, string str, string helper[ ], string temp, vector<string>&res){
        if(index >= str.size()){
            res.push_back(temp);
            return ;
        }

        string s = helper[str[index]-'0'];

        for(char ch : s){
            temp.push_back(ch);
            solve(index+1,str,helper,temp,res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res;
        string temp = "";

        string helper[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(0,digits,helper, temp,res);
        return res;
    }
};