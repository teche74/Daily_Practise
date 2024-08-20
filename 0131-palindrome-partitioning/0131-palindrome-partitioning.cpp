class Solution {
public:
    bool palli(string  & str){
        int low = 0 , high = str.size()-1;

        while(low < high){
            if(str[low] != str[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    void solve(int low, string  & s, vector<string> temp , vector<vector<string>> & res){
        if(low >= s.size()){
            res.emplace_back(temp);
            return;
        }

        for(int high = low ; high < s.size() ; high++){
            string ptr = s.substr(low, high - low +1);
            if(palli(ptr)){
                temp.emplace_back(ptr);
                solve(high+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;

        solve(0 ,s , temp,res);
        return res;
    }
};