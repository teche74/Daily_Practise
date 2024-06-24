class Solution {
public:
    double myPow(double x, int n) {
        unordered_map<int, double> memo; 

        return powHelper(x, n, memo);
    }

private:
    double powHelper(double x, int n, unordered_map<int, double>& memo) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;

        if (memo.find(n) != memo.end())
            return memo[n];

        double result = powHelper(x, n / 2, memo);
        result *= result;

        if (n % 2 != 0) {
            if (n > 0)
                result *= x;
            else
                result *= 1 / x;
        }

        memo[n] = result;
        return result;
    }
};
