class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>res;
        string t = to_string(n);
        int len =  t.size();

        while(n > 9){
            if((n / (int)pow(10 , len-1)) != 0)
                res.push_back(pow(10 , len-1) * (n / (int)pow(10 , len-1)));
            n%=(int)pow(10 , len-1);
            len--;
        }

        if(n > 0)
            res.push_back(n);
        return res;
    }
};