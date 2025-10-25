class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size() ;

        if(numRows == size || numRows == 1) return s;

        int row = 0 , index = -1;

        vector<string>temp(numRows , "");

        for(char ch : s){
            temp[row].push_back(ch);


            if(row == 0 || row == numRows-1){
                index *= -1;
            }
            row += index;
        }


        string res = "";

        for(string str : temp){
            res += str;
        }

        return res;
    }
};