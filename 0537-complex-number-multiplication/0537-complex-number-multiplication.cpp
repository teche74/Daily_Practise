class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a = 0 , b= 0 ,c = 0 ,d = 0;

        int plus_ind = -1;

        for(int i =0; i < num1.size() ; i++){
            if(num1[i] == '+'){
                plus_ind = i;
                break;
            }
        }

        a = stoi(num1.substr(0,plus_ind));
        b = stoi(num1.substr(plus_ind+1));

        plus_ind = -1;

        for(int i =0; i < num2.size() ; i++){
            if(num2[i] == '+'){
                plus_ind = i;
                break;
            }
        }

        c = stoi(num2.substr(0,plus_ind));
        d = stoi(num2.substr(plus_ind+1));

        string res =  to_string( (a*c) - (b*d) ) + "+"+ to_string((a*d) + (b*c)) + "i";

        return res;

    }
};