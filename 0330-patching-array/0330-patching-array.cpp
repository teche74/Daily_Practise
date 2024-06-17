class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res{0} ;
        long long miss{1} , i=0;

        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss+=nums[i];
                i++;
            }
            else{
                miss+=miss;
                res++;
            }
        } 

        return res;

    }
};