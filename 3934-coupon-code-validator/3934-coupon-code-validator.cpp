class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int size = code.size();
        vector<string>res;
        unordered_map<string,vector<string>>map;

        function<bool(string)> valid_buiss = [&](string code)->bool{
            return code ==  "electronics" || code == "grocery" || code == "pharmacy" || code == "restaurant";
        };

        function<bool(string)> valid_code = [&](string code)->bool{
            if(code.empty()) return false;

            for(char ch : code){
                if(isalpha(ch) || isdigit(ch) || ch == '_'){

                }
                else{
                    return false;
                }
            }
            return true;
        };
        
        
        for (int i = 0; i < size; i++) {
            if (isActive[i] && valid_buiss(businessLine[i]) && valid_code(code[i])) {
                map[businessLine[i]].push_back(code[i]);
            }
        }

        for(auto &t : map){
            sort(t.second.begin() , t.second.end());
        }


        for(auto t : {"electronics", "grocery", "pharmacy", "restaurant"}){
            
            for(string x : map[t]){
                res.push_back(x);
            }
        }

        return res;
    }
};