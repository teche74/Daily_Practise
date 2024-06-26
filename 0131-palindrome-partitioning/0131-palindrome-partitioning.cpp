class Solution {
public:
    bool palli(const string & str, int low , int high){
        while(low<high && str[low] == str[high]){
            low++;
            high--;
        }

        return low >=high;
    }
    void solve(int index, const string  & s, vector<string> & temp, vector<vector<string>>&res){
        if(index >= s.size()){
            res.emplace_back(temp);
            return;
        }

        for(int i = index ; i < s.size() ; i++){
            if(palli(s,index,i)){
                temp.emplace_back(s.substr(index,i-index+1));
                solve(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;

        solve(0,s,temp,res);

        return res;
    }
};