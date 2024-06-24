class Solution {
public:
    double solve(int n, double a){
        double ans=1;
        for(;n; n/=2){
                if (n & 1) {
                     ans *= a;
                }
            a *= a;
        }
        return  ans;
    }
    double myPow(double x, int n) {
        return n >= 0  ? solve(n,x) : 1/solve(n,x);
    }
};