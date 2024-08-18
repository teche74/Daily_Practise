class Solution {
public:
    string keypad[10] = {"","","abc", "def" , "ghi" ,"jkl" , "mno", "pqrs", "tuv", "wxyz"};

    void solve(int index, string  & input , string temp  , vector<string> & res){
        if(index >= input.size()){
            res.emplace_back(temp);
            return;
        }

        string val = keypad[input[index] - '0'];

        for(char ch : val){
            temp.push_back(ch);
            solve(index+1, input , temp ,  res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res;
        string temp = "";

        solve( 0 , digits, temp,res);

        return res;    
    }
};