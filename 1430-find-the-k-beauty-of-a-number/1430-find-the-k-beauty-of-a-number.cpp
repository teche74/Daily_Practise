class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str =  to_string(num);

        int high = 0 , size = str.size(), res = 0;

        while(high +k <= size){

            int val = stoi(str.substr(high ,  k));

            res += (val != 0  && num % val == 0);
            high++;
        }

        return res;
    }
};