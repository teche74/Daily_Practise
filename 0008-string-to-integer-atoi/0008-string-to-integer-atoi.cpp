class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int ind = 0 ;
        bool sign  = false;
        long long res= 0 ;

        while(ind < size && s[ind] == ' ') ind++;

        if(s[ind] == '-'){
            sign  = true;
            ind++;
        }
        else if(s[ind] == '+'){
            ind++;
        }

        while(ind < size && isdigit(s[ind])){
            res*=10;
            res+=(s[ind] - '0');
            ind++;

            if(res >= INT_MAX || res <= INT_MIN) break;
        }

        if(sign) res*=-1;

        if(res >= INT_MAX) return INT_MAX;
        if(res <= INT_MIN) return INT_MIN;

        return res;
    }
};