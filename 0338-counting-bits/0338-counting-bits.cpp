class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,0);

        for(int i = 1; i <= n ; i++){
            //  half the bit  && aloso check if it is odd;
            res[i] = res[i/2];

            if(i & 1){
                res[i]++;
            }
        }
        return res;
    }
};