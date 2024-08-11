class Solution {
public:
    int solve(string & str , char val , int miss){
        int low = 0 , high = 0 , size = str.size() , res = 0;

        while(high < size){
            miss-=(str[high] != val);

            while(miss < 0){
                miss+=(str[low] != val);
                low++;
            }

            res = max(res, high - low+1);
            high++;
        }
        return res;
    }
    int maxConsecutiveAnswers(string str, int k) {
        return max(solve(str,'T', k) , solve(str, 'F', k));

    }
};