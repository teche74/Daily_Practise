class Solution {
public:
    bool palli(string str){
        int i = 0 , j = str.size()-1;

        while(i < j ){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    void solve(int index , string & s, vector<string> & temp, vector<vector<string>> &res){
        if(index >= s.size()){
            res.emplace_back(temp);
            return;
        }

        for(int i = index ;i < s.size() ; i++){
            string ptr = s.substr(index,i- index +1);
            if(palli(ptr)){
                temp.emplace_back(ptr);
                solve(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;

        solve(0 ,s, temp,res);

        return res;
    }
};