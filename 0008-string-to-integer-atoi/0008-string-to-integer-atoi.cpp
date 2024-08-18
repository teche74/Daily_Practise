class Solution {
public:
    int myAtoi(string s) {
        int index = 0 , size = s.size();
        long long val = 0 ;
         bool sign  =false; 

        while(index < size && isspace(s[index])) index++;

        if(index < size && s[index] == '-'){
            sign = true;
            index++;
        }
        else if(s[index] == '+'){
            index++;
        }

        while(index < size && isdigit(s[index]) ){
            val*=10;
            val +=(s[index] - '0');
            if(val >= INT_MAX || val <= INT_MIN) break;
            index++;
        }

        if(sign) val *= -1;

        if(val >= INT_MAX) return INT_MAX;
        if(val <= INT_MIN) return INT_MIN;

        return val;
    }
};