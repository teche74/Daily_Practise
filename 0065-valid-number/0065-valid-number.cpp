class Solution {
public:
    bool isNumber(string s) {
        int ind = 0 , size = s.size(); 


        auto digits_mat_dekho = [&](int &ind) {
            int curr = ind;
            while (ind < size && isdigit(s[ind])) {
                ind++;
            }
            return ind > curr; 
        };

        // space rhne do 

        while(ind < size && isspace(s[ind])) ind++;

        if(ind < size && s[ind] == '+' || s[ind] == '-') ind++;

        bool numeric = false;

        // digit htao
        if(digits_mat_dekho(ind)){
            numeric = true;
        }

        if (ind < size && s[ind] == '.') {
            ++ind;
            // decimal bhi dekhliya
            if (digits_mat_dekho(ind)) {
                numeric = true;
            }
        }

        // ab exponent ki bari
        if (numeric && ind < size && (s[ind] == 'e' || s[ind] == 'E')) {
            ++ind;
            numeric = false; 

            if (ind < size && (s[ind] == '+' || s[ind] == '-')) ++ind;

            if (digits_mat_dekho(ind)) {
                numeric = true;
            }
        }


        while (ind < size && isspace(s[ind])) ++ind;

        return numeric && ind == size;
    }
};