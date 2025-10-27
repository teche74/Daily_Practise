class Solution {
public:
    long long removeZeros(long long n) {
        string res = "";

        while(n > 0){
            if(n % 10 != 0){
                res.push_back((n % 10) + '0');
            }
            n /= 10;
        }

        reverse(res.begin(), res.end());

        return stoll(res);
    }
};