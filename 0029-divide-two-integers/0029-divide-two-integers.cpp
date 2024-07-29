class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = dividend > 0  ^ divisor > 0 ? -1 : 1;
        
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long  divd = labs(dividend) , divs = labs(divisor);

        int res = 0;

        while(divd >= divs){
            int temp = divs;
            int count  = 1;

            while(divd >= temp << 1){
                temp <<= 1;
                count <<= 1;
            }
            res+=count;
            divd -=temp;
        }  

        return res * sign;
    }
};