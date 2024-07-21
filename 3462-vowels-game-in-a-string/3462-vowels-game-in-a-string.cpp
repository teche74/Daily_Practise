class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels  = 0 ;

        for(char ch : s){
            if(ch == 'a' || ch == 'e' || ch =='o' || ch == 'i' || ch =='u'){
                return true;
            }
        }
        return false;
    }
};