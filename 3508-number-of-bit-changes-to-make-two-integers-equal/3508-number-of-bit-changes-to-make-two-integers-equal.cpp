class Solution {
public:
    int minChanges(int n, int k) {
        if(k > n ) return -1;

        bitset<32> n_bit(n) , k_bit(k);

        int res = 0;

        for(int i = 0; i < 32 ; i++){
            if(n_bit[i] == 1 &&  k_bit[i] == 0){
                res++;
            }
            else if(n_bit[i] == 0 && k_bit[i] == 1){
                return -1;
            }
        }
        return res;
    }
};