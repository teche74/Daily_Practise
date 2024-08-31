class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();

        if(size == 1 || numRows == 1 || numRows > size) return s;

        vector<string>store(numRows , "");

        int row = 0 , dir = -1;

        for( char ch : s){
            store[row].push_back(ch);

            if(row == 0 || row == numRows -1){
                dir*=-1;
            }

            row += dir;
        }

        string res = "";

        for(auto t  : store){
            res += t;
        }

        return res;
    }
};