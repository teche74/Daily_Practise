class Solution {
public:
    bool palli(const string & ptr, int low, int high){

        while(low <= high){
            if(ptr[low] != ptr[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    void solve(int index,const string s, vector<vector<string>> &res , vector<string> & temp){
        if(index >= s.size()){
            res.emplace_back(temp);
            return;
        }

        for(int i = index; i < s.size() ;i++){
            if(palli(s, index, i)){
                temp.emplace_back(s.substr(index,i-index+1));
                solve(i+1,s,res,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;

        solve(0, s, res, temp);

        return res;
    }
};