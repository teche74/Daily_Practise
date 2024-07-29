class Solution {
public:
    string keypad[10] = {"","","abc", "def" , "ghi" ,"jkl" , "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res;
        string temp = "";

        function<void(int)> solve = [&](int index){
            if(index >= digits.size()){
                res.emplace_back(temp);
                return;
            }

            string ptr = keypad[digits[index] - '0'];

            for(char ch : ptr){
                temp.push_back(ch);
                solve(index+1);
                temp.pop_back();
            }
        };

        solve(0);

        return res;

    }
};