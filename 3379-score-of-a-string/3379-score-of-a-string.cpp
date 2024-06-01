class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0 ;

        int size= s.size();

        for(int i =1; i <size ;i++){
            sum += abs(s[i-1]  - s[i]);
        }

        return sum;
    }
};