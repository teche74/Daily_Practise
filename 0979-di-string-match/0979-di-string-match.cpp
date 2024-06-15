class Solution {
public:
    vector<int> diStringMatch(string s) {
        int size = s.size();

        int low = 0 , high  = size;

        vector<int>res;

        for(int i =0 ; i <size ; i ++){
            if(s[i] == 'I'){
                res.push_back(low);
                low++;
            }
            else{
                res.push_back(high);
                high--;
            }
        } 
        res.push_back(low);

        return res;
    }
};