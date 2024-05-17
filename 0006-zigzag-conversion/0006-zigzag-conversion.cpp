class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();

        if(numRows == 1) return s;
        if(size < numRows) return s;

        int row = 0 , dir = -1;

        vector<char>store[numRows];

        for(char ch : s){
            store[row].push_back(ch);

            if(row == 0 || row == numRows-1){
                dir *=-1;
            }

            row +=dir;
        }

        string str = "";

        for(auto t : store){
            for(auto p : t){
                str.push_back(p);
            }
        }

        return str;
    }
};