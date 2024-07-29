class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();

        if(size < numRows ) return s;
        if(numRows == 1) return s;

        //  brute 
        vector<char>st[numRows];
        int row = 0 , dir = -1; 

        for(char ch : s){
            st[row].push_back(ch);

            if(row == 0 || row == numRows-1){
                dir*=-1;
            }

            row+=dir;
        }

        string res = "";

        for(auto t : st){
            for(char ch : t){
                res.push_back(ch);
            }
        }

        return res;

    }
};