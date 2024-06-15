class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;
        int t = n;

        if( t & 1 ) {
            res.push_back(0);
            t--;
        }

        int val =1;



        while(res.size()  != n){
            res.emplace_back(val);
            res.emplace_back(-val);
            val++;
        }

        return res;
    }
};