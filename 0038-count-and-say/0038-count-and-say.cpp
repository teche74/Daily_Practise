class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string temp =  countAndSay(n-1);
        string upd = "";

        for(int i = 0 ; i < temp.size(); i++){
            int j  =i+1;

            while(j < temp.size() && temp[j] == temp[i]) j++;

            upd.push_back((j-i) + '0');
            upd.push_back(temp[i]);

            i = j-1;
        }
        return upd;
    }
};