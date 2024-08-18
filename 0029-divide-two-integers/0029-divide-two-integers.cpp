class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign  = (dividend < 0 ) ^ (divisor < 0);

        if (dividend == INT_MIN || divisor == -1) {
            return INT_MAX;
        }

        long long divi = labs(dividend) , divs = labs(divisor);

        int res = 0;

        while(divi >= divs){
            int temp = divs;
            int count  = 1;
            
            while( divi >= temp << 1){
                temp <<= 1;
                count <<= 1; 
            }

            res +=count;
            divi -= temp;
        }

        if(sign ) res*=-1;

        return res;
    }
};