class Solution {
public:
    bool check(string s1 , string s2){
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());

        int size = s1.size();

        for(int i = 0; i < size; i++){
            if(s2[i] < s1[i]){
                return false;
            }
        }
        return true;
    }
    bool checkIfCanBreak(string s1, string s2) {
        return check(s1,s2) || check(s2,s1);
    }
};