class Solution {
public:
    double solve(double x, int n){
        double res = 1;

        for(;n ; n/=2){
            if(n & 1){
                res *= x;
            }
                x*=x;
        }

        return res;
    }
    double myPow(double x, int n) {
        return n < 0  ? 1 / solve(x,n) : solve(x,n); 
    }
};