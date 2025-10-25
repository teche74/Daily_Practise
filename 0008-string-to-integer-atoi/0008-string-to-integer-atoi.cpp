class Solution {
public:
    int myAtoi(string s) {
        int index = 0  , size = s.size();
        bool sign = false;

        while(index < size && isspace(s[index])) index++;

        if(s[index] == '+'){
            sign  = false;
            index++;
        }
        else if(s[index] == '-'){
            sign = true;
            index++;
        }

        long val = 0;

        while(index < size && s[index] >= '0' && s[index] <= '9'){
            val = val * 10 + (s[index] - '0');
            index++;
            if(val >= INT_MAX || val <= INT_MIN) break;
        }

        if(sign) val *= -1;

        if(val >= INT_MAX) return INT_MAX;
        if(val <= INT_MIN) return INT_MIN;

        return val;
    }
};