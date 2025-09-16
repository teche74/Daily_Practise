class Solution {
public:
    string generateTheString(int n) {
        if(n & 1) return string(n , 'a');

        string res = ""; 
        for(int i = 'a' ; i < 'z' ; i++){
            for(int j = n - res.size(); j >= 0; j--){
                if(j & 1){
                    res += string(j ,i);
                    // cout<<string(j ,i)<<endl;
                    break;
                }
            }
        }

        return res;
    }
};