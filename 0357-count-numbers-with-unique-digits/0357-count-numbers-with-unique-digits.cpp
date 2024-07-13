class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        
        int count = 10; 
        
        int uni = 9;
        int avail = 9;
        
        for (int i = 2; i <= n; i++) {
            uni *= avail;
            count += uni;
            avail--;
        }
        
        return count;
    }
};