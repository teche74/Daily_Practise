class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n);
        res[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0;
        int two_multiple = 2;
        int three_mulitple = 3;
        int five_mulitple = 5;
        
        for (int i = 1; i < n; i++) {
            int next = min(two_multiple, min(three_mulitple, five_mulitple));
            res[i] = next;
            
            if (next == two_multiple) {
                i2++;
                two_multiple = res[i2] * 2;
            }
            if (next == three_mulitple) {
                i3++;
                three_mulitple = res[i3] * 3;
            }
            if (next == five_mulitple) {
                i5++;
                five_mulitple = res[i5] * 5;
            }
        }
        
        return res[n-1];
    }
};
