class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return  "1";
        }

        string str = countAndSay(n-1);
        char prev = str[0]; 
        int count  = 0;
        string res = "";

        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == prev){
                count++;
            }
            else{
                res += to_string(count) + prev;
                prev =str[i];
                count =1;
            }
        }
        res += to_string(count) + prev;
        return res;
    }
};