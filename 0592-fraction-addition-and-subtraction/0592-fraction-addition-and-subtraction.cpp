class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1, n = expression.size(), num, den;
        for (int i = 0; i < n;) {
            int sign = (expression[i] == '-') ? -1 : 1;
            if (expression[i] == '-' || expression[i] == '+') i++;
            num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i++] - '0');
            }
            num *= sign;
            i++;
            den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i++] - '0');
            }
            numerator = numerator * den + num * denominator;
            denominator *= den;
            int g = gcd(abs(numerator), denominator);
            numerator /= g;
            denominator /= g;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};