class Solution {
public:
    int countPrimes(int n) {
        vector<int>check(n+1,1);

        for(int i = 2; i*i < n ; i++){
            if(check[i] == 1){
                for(double j = i*i ; j <= n ; j+=i){
                    check[j]++;
                }
            }
        }

        int count = 0;

        for(int i=2;i < n;i++){
            if(check[i] == 1){
                count++;
            }
        }
        return count;
    }
};