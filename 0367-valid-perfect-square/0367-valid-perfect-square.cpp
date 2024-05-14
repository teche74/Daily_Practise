class Solution {
public:
    bool isPerfectSquare(int num) {
        int side =1;

        for(long long i = num/2 ; i >=1 ;i/=2 ){
            while( (long long)(side+i)*(side+i) < num) side+=i;
        }

        if(side == 1) return true;

        return (long long)(side+1) * (side+ 1) == num;
    }
};