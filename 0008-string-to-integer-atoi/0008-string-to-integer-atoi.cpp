class Solution {
public:
    int myAtoi(string s) {
        int size  = s.size();

        bool sign  = false; 
        int ind = 0 ;
        long long val = 0;

        while(ind < size  && s[ind] == ' ') ind++;

        if(s[ind]  == '-'){
            sign = true;
            ind++;
        }
        else if(s[ind] == '+'){
            ind++;
        }

        while(ind < size  && isdigit(s[ind])){
            val *=10;
            val+=(s[ind]-'0');
            if(val >= INT_MAX || val <= INT_MIN) break;
            ind++;
        }

        if(sign) val*=-1;

        if(val >= INT_MAX) return INT_MAX;
        if(val <=INT_MIN) return INT_MIN;
        return val;
    }
};