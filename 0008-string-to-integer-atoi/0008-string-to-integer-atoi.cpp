class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int index = 0 ;
        bool sign = false;
        long long  val = 0;


        while(index < size && isspace(s[index])) index++; 


        if(s[index] == '-'){
            sign = !sign;
            index++;
        } 
        else if(s[index] == '+'){
            index++;
        }

        while(index  < size && isdigit(s[index])){
            val*=10;
            val+=(s[index] - '0');
            if(val >=  INT_MAX || val <= INT_MIN) break;
            index++;
        }

        if(sign) val*=-1;
        if(val >= INT_MAX) return INT_MAX;
        if(val <= INT_MIN) return INT_MIN;
        return val;
    }
};