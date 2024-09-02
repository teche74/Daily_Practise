class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int size = chalk.size();

        int sum = 0;

        for(int i = 0; i < size ; i++){
            if(sum + chalk[i] > k){
                return i;
            }
            else{
                sum+=chalk[i];
            }
        }

        k %= sum;

        for(int i =0 ; i < size ; i++){
            if(k - chalk[i] >= 0){
                k-= chalk[i];
            }
            else{
                return i;
            }
        }

        return -1;
    }
};