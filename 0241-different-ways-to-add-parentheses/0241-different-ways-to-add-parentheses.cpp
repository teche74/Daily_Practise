class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        int size = s.size();

        function<int(int,int,char)> calc = [&](int val1, int val2, char oper){
            if(oper == '+') return val1 + val2;
            if(oper == '-') return val1 - val2;
            if(oper == '*') return val1 * val2;
            return 0;
        };

        vector<int>res;
        bool flag =true;

        for(int i = 0 ;i < size ; i++){
            if(!isdigit(s[i])){
                flag = false;
                vector<int>left = diffWaysToCompute(s.substr(0,i));
                vector<int>right = diffWaysToCompute(s.substr(i+1));

                for(auto t : left){
                    for(auto r : right){
                        res.emplace_back(calc(t,r,s[i]));
                    }
                }
            }
        }

        if(flag) res.emplace_back(stoi(s));

        return res;
    }
};