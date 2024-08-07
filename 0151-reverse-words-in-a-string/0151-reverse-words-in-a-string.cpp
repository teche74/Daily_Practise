class Solution {
public:
    string reverseWords(string s) {
        int size = s.size(), prev = size - 1;
        while (prev >= 0 && isspace(s[prev])) prev--;
        string res = "";

        while (prev >= 0) {
            int end = prev;
            while (prev >= 0 && !isspace(s[prev])) prev--; 
            if (res.size() > 0) res.push_back(' '); 
            res += s.substr(prev + 1, end - prev); 

            while (prev >= 0 && isspace(s[prev])) prev--; 
        }

        return res;
    }
};