class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size() , m = num2.size();

        vector<int>res(n+ m , 0);

        for(int i = n-1 ; i>= 0 ; i--){
            for(int j = m-1; j >= 0 ; j--){
                int val = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1];
                res[i+j] += val /10;
                res[i+j+1] = val%10;
            }
        }

        string str = "";

        for(int x  : res){
            if( !(str.empty() && x == 0)){
                str.push_back(x + '0');
            }
        }

        return str == "" ? "0" : str;
    }
};