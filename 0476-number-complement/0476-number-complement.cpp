class Solution {
public:
    int findComplement(int num) {
        int res = 0 ;

        int ind = 0;

        while(num){
            if(num % 2 == 0){
                res+=pow(2,ind);
            }
            ind++;
            num/=2;
        }

        return res;
    }
};