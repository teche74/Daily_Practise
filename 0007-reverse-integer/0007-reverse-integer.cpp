class Solution {
public:
    int reverse(int x) {
        long long  res = 0;

        while(x){
            res*=10;
            res += x%10;
            if(res >= INT_MAX || res <= INT_MIN) return 0;
            x/=10;
        } 

        return res;
    }
};