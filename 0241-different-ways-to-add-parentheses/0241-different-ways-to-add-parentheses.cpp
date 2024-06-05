class Solution {
public:
    int calci(int x, int y , char oper){
        switch (oper){
            case '+':
                return x+y;
            case '-':
                return x-y;
            case '*':
                return x*y;
        }

        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        vector<int>res;
        bool flag  =true;

        for(int i =0;i < exp.length() ;i++){
            if(!isdigit(exp[i])){
                flag = false;
                vector<int> l = diffWaysToCompute(exp.substr(0,i));
                vector<int> r = diffWaysToCompute(exp.substr(i+1));

                for(int x : l){
                    for(int y : r){
                        res.push_back(calci(x,y,exp[i]));
                    }
                }
            }
        } 

        if(flag) res.push_back(stoi(exp));

        return res;
    }
};