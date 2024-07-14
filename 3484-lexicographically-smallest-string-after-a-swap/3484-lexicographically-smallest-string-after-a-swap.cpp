class Solution {
public:
    string getSmallestString(string s) {
        int size = s.size();
        string res = s;

        for(int i = 0 ; i < size-1; i++){
            if( (s[i] - '0') % 2 == (s[i+1]-'0') % 2){
                swap(s[i] , s[i+1]);
                res = res > s ? s : res;
                swap(s[i] , s[i+1]);
            }
        }
        return res;
    }
};