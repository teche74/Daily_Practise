class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string res = "";

        int size  = words.size();

        sort(words.begin(), words.end() , [](const string &str, const string &ptr) 
        { return str.size() > ptr.size(); }
        );

        for(int i =0; i <size; i++){
            if(res.find(words[i] +'#') == string :: npos){
                res+=words[i] + '#';
            }
        }

        return res.size();
    }
};