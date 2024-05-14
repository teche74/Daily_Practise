class Solution {
public:
    int mySqrt(int x) {
        int num = 0;

        for(long long i = x/2 ;i >= 1 ;i/=2){
            while(num+i < x  && (num + i)* (num+i) < x ) num+=i;
        }

        if( (long long)(num+1) * (num+1)  > x ) return num;

        return num+1;
    }
};