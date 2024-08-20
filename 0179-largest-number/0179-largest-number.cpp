class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>res;

        for(auto t : nums){
            res.emplace_back(to_string(t));
        }

        sort(res.begin(), res.end() , [&](string a , string b){
            return a + b > b + a;
        });


        string ans = "";

        for(auto t : res){
            ans+=t;
        }

        return ans[0] == '0' ? "0" : ans; 
    }
};