class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();

        for(int i = 0 ; i <size ; i++){
            bool dupl = false;
            
            for(int j = 0; j < size; j++){
                if (nums[i] == nums[j] && i != j) {
                    dupl = true;
                    break;
                }
            }

            if(!dupl) return nums[i];
        }

        return -1;
    }
};