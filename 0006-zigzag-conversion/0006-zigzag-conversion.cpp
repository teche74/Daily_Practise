class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();

        if( numRows == 1 || s.size() < numRows ) return s;

        vector<string>st(size);

        int row = 0 , dir = -1;

        for(char ch : s){
            st[row].push_back(ch);

            if(row == 0 || row == numRows-1){
                dir *= -1;
            }

            row+=dir;
        }

        string res = "";

        for(auto t : st){
            res+=t;
        }

        return res;

    }
};