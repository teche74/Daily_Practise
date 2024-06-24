class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;

        double result = myPow(x, n / 2);
        if (n % 2 == 0)
            return result * result;
        else if (n > 0)
            return x * result * result;
        else
            return (1 / x) * result * result;
    }
};