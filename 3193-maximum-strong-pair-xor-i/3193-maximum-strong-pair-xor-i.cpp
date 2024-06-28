class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        // brute force
        // int size = nums.size(), res = 0;
        // for(int i =0 ; i < size ; i++){
        //     for(int j = i+1; j <size; j++){
        //         if( abs(nums[i] - nums[j])  <= min(nums[i], nums[j])){
        //             res = max(res, nums[i] ^ nums[j]);
        //         }
        //     }
        // }
        // return res;


        // use silding window
        sort(nums.begin(), nums.end());
        int size = nums.size(), high = 0, low = 0 ,res = INT_MIN;

        while(high < size){
            
            while(high < nums.size() && abs(nums[low] - nums[high]) <= min(nums[low], nums[high])){
                res = max(res, nums[low] ^ nums[high]);
                high++;
            }
            low++;
            high = low+1;

        }

        return res;
    }
};