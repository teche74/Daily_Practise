class Solution {
public:

    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        string prev = countAndSay(n-1);
        string res = "";

        int count = 0;
        char curr = prev[0];

        for(char ch : prev){
            if(ch == curr){
                count++;
            }
            else{
                res += to_string(count) + curr;
                curr =ch;
                count =1;
            }
        }

        res += to_string(count) + curr;
        return res;
    }
};