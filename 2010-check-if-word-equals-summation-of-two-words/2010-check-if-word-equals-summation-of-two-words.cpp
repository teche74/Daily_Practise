class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int val1 = 0, val2 = 0, val3= 0;

        for(char ch : firstWord){
            val1 = val1*10 + (ch - 'a');
        }

        for(char ch : secondWord){
            val2 = val2 *10 + (ch - 'a');
        }

        for(char ch : targetWord){
            val3 = val3*10 + (ch - 'a');
        }

        return val1 +val2 == val3; 
    }
};