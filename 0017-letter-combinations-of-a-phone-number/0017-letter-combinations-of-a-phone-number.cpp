class Solution {
public:
    void solve(int index, string &input, vector<string> & res, string temp, string helper[ ]){
        if(temp.size() == input.size()){
            res.emplace_back(temp);
            return;
        }

        int dig = input[index] - '0';

        string tp = helper[dig];

        for(auto t : tp){
            temp.push_back(t);
            solve(index+1,input,res,temp, helper);
            temp.pop_back();
        } 
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string>res;
        string temp = "";

        string helper[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(0,digits, res, temp, helper);

        return res;
    }
};