class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN  && divisor == -1 ) return INT_MAX;

        long long jisko_devide_krna = llabs(dividend) , jisse_devide_krna = llabs(divisor), ans= 0;

        int sign  = (divisor > 0) ^ (dividend > 0) ? -1  : 1;


        while(jisko_devide_krna >= jisse_devide_krna){
            long temp = jisse_devide_krna, m =1;

            while(temp << 1  <= jisko_devide_krna){
                temp <<= 1;
                m <<=1;
            }

            jisko_devide_krna -=temp;
            ans+=m;
        }

        return sign  * ans;
    }
};