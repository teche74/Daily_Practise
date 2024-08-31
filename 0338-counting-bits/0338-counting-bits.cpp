class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>res(n+1,  0);

        for(int  i = 0 ; i <= n ; i++){
            res[i] = res[i >> 1];

            if(i & 1){
                res[i]++;
            }
        }

        return res;
    }
};