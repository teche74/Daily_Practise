class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "", str2 ="";

        for(string t : word1){
            str1 +=t;
        }

        for(string t : word2){
            str2 +=t;
        }

        return str1 == str2;
    }
};