class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0) return "0";

        bool sign = (num < 0 ) ^ (den < 0);

        long nume = labs(num);
        long denom = labs(den);

        string res = (sign ? "-" : "") + to_string(nume / denom);

        long rem = nume % denom;
        if (rem == 0) return res;


        res += '.';

        unordered_map<long,int>rem_map;

        while(rem != 0){
            if (rem_map.find(rem) != rem_map.end()) {
                res.insert(rem_map[rem], "(");
                res += ')';
                break;
            }

            rem_map[rem] = res.size();
            
            rem *= 10;
            res += to_string(rem / denom);
            rem %= denom;
        }

        return res;


    }
};