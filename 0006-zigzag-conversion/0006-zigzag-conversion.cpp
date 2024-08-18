class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();

        if(numRows  > size ||  numRows == 1) return s;

        int row = 0 , dir = -1;

        // slow performance
        // vector<char>st[numRows];
        // for(char ch : s){
        //     st[row].push_back(ch);

        //     if(row == numRows -1 || row == 0){
        //         dir *= -1;
        //     }

        //     row +=dir;
        // } 

        vector<string>st(numRows , "");
        for(char ch : s){
            st[row].push_back(ch);

            if(row == numRows -1 || row == 0){
                dir *= -1;
            }

            row +=dir;
        } 

        string res = "";

        for(auto str  :st){
            res += str;
        } 

        return res;
    }
};