class Solution {
public:
    vector<int> diffWaysToCompute(string s) {

       function<int(int,int,char)> calc = [](int num1, int num2 , char oper){
            if(oper == '+'){
                return num1 + num2;
            }
            else if(oper == '-'){
                return num1 - num2;
            }
            else if(oper == '*'){
                return num1 * num2;
            }
            return 0;
       };

       vector<int>res;
       bool flag = true;
       int size = s.size();

       for(int i =0; i <size; i++){
            if(!isdigit(s[i])){
                flag  =false;
                vector<int>left = diffWaysToCompute(s.substr(0,i));
                vector<int>right = diffWaysToCompute(s.substr(i+1));

                for(int c : left){
                    for(int t : right){
                        res.emplace_back(calc(c,t,s[i]));
                    }
                }
            }
        }

        if(flag) res.push_back(stoi(s));
        
        return res;
    }
};