class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for (long long i = 0; i * i <= c; i++) {
            long long b2 = c - i * i;
            long long b = sqrt(b2);
            if (b * b == b2) {
                return true;
            }
        }
        return false;
    }
};