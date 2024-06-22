class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();

        if(numRows == 1) return s;

        if(size  < numRows) return s;

        vector<char>store[numRows];

        int  row = 0 , dir = -1;

        for(char ch : s){
            store[row].push_back(ch);


            if(row == 0 || row == numRows-1){
                dir*=-1;
            }

            row+=dir;
        }

        string res = "";

        for(auto s : store){
            for(auto ch  : s){
                res.push_back(ch);
            }
        }
        return res;
    }
};