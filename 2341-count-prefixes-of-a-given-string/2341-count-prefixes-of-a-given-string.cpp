class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count =0 ;

        for(int i= 0; i< words.size() ;i++){
            if(s[0] == words[i][0]){
                if(s.substr(0 ,words[i].size()) == words[i]) count++;
            }
        }
        return count;
    }
};