class Solution {
public:
    int calc(int a, int b , char oper){
        if(oper == '+') return a+b;
        if(oper == '-') return a-b;
        if(oper == '*') return a*b;

        return -1;
    }
    vector<int> diffWaysToCompute(string expression) {
        int size = expression.size();

        bool flag = true;
        vector<int>res;

        for(int i = 0 ; i < size;  i++){
            if(!isdigit(expression[i])){
                flag = false;

                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for(auto l : left){
                    for(auto r : right){
                        res.emplace_back(calc(l,r,expression[i]));
                    }
                }
            }
        }

        if(flag) res.emplace_back(stoi(expression));
        return res;
    }
};