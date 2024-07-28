class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int lim = (int)(sqrt(r));

        vector<bool> prime(lim + 1, true);
        prime[0] = prime[1] = false; 


        for (int i = 2; i * i <= lim; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    prime[j] = false;
                }
            }
        }

        int count = r - l +1;

        for(int i = 2 ; i <= lim; i ++){
            int val = i *i ;
            if(prime[i] &&   val >= l && val <= r){
                count--;
            }
        }

        return count;
    }
};