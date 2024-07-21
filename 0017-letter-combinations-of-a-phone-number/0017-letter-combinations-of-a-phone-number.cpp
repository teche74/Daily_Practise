class Solution {
public:
    void solve(int index, string str , string helper[10] , string temp , vector<string> & res ){
        if(index >= str.size()){
            res.emplace_back(temp);
            return;
        }

        string tp = helper[str[index] - '0'];

        for(char ch : tp){
            temp.push_back(ch);
            solve(index+1,str,helper,temp,res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string helper[10] = {"","", "abc" , "def", "ghi" , "jkl" ,"mno", "pqrs" , "tuv" , "wxyz"};

        vector<string>res;
        string temp = "";

        solve(0, digits, helper, temp,res);
        return res;
    }
};