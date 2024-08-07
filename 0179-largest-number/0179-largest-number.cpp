class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>vals;

        for(auto t : nums){
            vals.emplace_back(to_string(t));
        }

        sort(vals.begin(), vals.end() , [&](string a , string b){
            return a + b > b + a; 
        });

        if(vals[0] == "0"){
            return "0";
        }

        string res = "";

        for(auto t : vals){
            res  += t;
        }
        return res;
    }
};