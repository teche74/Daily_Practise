class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int total_one = 0 ;

        for(int x :  nums){
            if(x & 1) total_one++;
        }


        if (total_one == 0 || total_one == nums.size())
            return 0;

        for(int i =0; i< total_one ; i++){
            nums.emplace_back(nums[i]);
        }

        int size = nums.size();

        int low = 0 ,  high = 0 , count_one = 0, res = size+1;

        while(high  < size){
            count_one+=(nums[high] == 1);

            while(high - low +1 > total_one){
                count_one-=(nums[low] == 1);
                low++;
            } 

            if (high - low + 1 == total_one) {
                res = min(res, total_one - count_one);
            }

            high++;
        }

        return res;

    }
};