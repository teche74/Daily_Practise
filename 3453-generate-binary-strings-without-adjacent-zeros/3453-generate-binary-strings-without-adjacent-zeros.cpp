class Solution {
public:
    void solve( int end,  string temp ,vector<string> & res){
        if(temp.size() == end){
            res.emplace_back(temp);
            return;
        }

        solve(end,temp + '1',res);
        
        if(temp.empty() || temp.back() == '1'){
            solve(end,temp + '0', res);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>res;
        string temp ;

        solve(n,temp,res);
        return res;
    }
};