class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size =  nums.size();

        double max_product =  nums[0], min_product = nums[0], res = nums[0];

        for(int i =1 ; i <size; i++){
            if(nums[i] < 0){
                swap(max_product, min_product);
            }

            max_product = max((double)nums[i] , (double)max_product * nums[i]);
            min_product = min((double)nums[i] , (double)min_product * nums[i]);

            res = max(res , max_product);
        }

        return res;
    }
};