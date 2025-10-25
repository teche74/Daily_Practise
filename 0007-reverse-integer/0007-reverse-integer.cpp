class Solution {
public:
    int reverse(int x) {
        if(x >= INT_MAX || x <= INT_MIN) return 0;
        long res = 0;
        bool sign = x > 0 ? false : true;
        x = x > 0 ? x : (x * -1);

        while(x > 0){
            res *= 10;
            res += (x  % 10);
            if(res >= INT_MAX || res <= INT_MIN) return 0;
            x /= 10;
        }

        return res * (sign ? -1 : 1);
    }
};