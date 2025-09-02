class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        string temp;

        vector<string> keyboard = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",  "wxyz"};

        function<void(int)> solve = [&](int index){
            if(index >= digits.size()){
                res.push_back(temp);
                return;            
            }


            int curr_digit = digits[index] - '0';
            for(char ch  : keyboard[curr_digit]){
                temp.push_back(ch);
                solve(index+1);
                temp.pop_back();
            } 
        };

        solve(0);

        return digits.empty() ? vector<string>{} : res;
    }
};