class Solution {
public:
    void solve(int index, string str,  string temp , vector<string> & res, int stops){
        if (stops == 0) {
            if (index == str.size()) {
                res.push_back(temp);
            }
            return;
        }

        int num = 0 ;


        for(int i = index; i < str.size() ; i++){
            num *= 10;
            num +=(str[i] - '0');

            if(num <= 255){
                if(i > index && str[index] == '0') break;
                
                string seg = to_string(num);
                if(stops > 1)
                    seg.push_back('.');
                
                solve(i+1,str,temp + seg,res,stops-1);
            }else{
                break;
            }
        }



    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        string temp = "";

        solve( 0 , s, temp,res , 4);

        return res;

    }
};