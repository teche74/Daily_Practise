class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];


        for(int i = 1 ; i < strs.size() ; i++){
            string temp = strs[i] , updated = "";
            for(int i = 0; i < min(temp.size() ,  res.size()) ; i++){
                if(temp[i] == res[i]){
                    updated.push_back(res[i]);
                }
                else{
                    break;
                }
            }
            res = updated;
        }

        return res;
    }
};