class Solution {
public:
    int reverse(int x) {
        long long val =  0;

        while(x){
            val*=10;
            val+=(x%10);
            if(val >= INT_MAX || val <= INT_MIN) return 0;
            x/=10;
        }  

        return val;
    }
};