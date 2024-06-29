class Solution {
public:
    int helper( const string & s , int k , char ch){
        int low =0  , high = 0 , size = s.size() , res = 0 ;
        int opers = 0;


        while( high < size){
            opers += (s[high] != ch);

            while(opers > k){
                opers -= (s[low] != ch);
                low++;
            }   

            res = max(res,high - low+1 );
            high++;
        }
        return res;
    }
    int maxConsecutiveAnswers(string arr, int k) {
        return max(helper(arr,k,'T'), helper(arr,k,'F')); 
    }
};