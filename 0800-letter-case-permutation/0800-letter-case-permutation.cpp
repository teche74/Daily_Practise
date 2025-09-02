class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string temp;
        int size = s.size();

        function<void(int)> call =[&](int index){
            if(index >= size){
                res.push_back(temp);
                return;
            }

            if(isdigit(s[index])){
                temp.push_back(s[index]);
            }
            else{
                temp.push_back(s[index]);
                call(index+1);
                temp.pop_back();
                if(islower(s[index])){
                    temp.push_back(toupper(s[index]));
                }
                else{
                    temp.push_back(tolower(s[index]));
                }
            }
            call(index+1);
            temp.pop_back();
        };

        call(0);
        return res;
    }
};