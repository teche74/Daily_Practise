class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int size = nums.size();
        long long count  = 0 ;

        int min_pos = -1, max_pos = -1, left = -1;


        for(int i = 0; i <size; i ++){
            
            if(nums[i] < minK || nums[i] > maxK){
                left = i;
                min_pos = -1;
                max_pos = -1;
            }

            if(nums[i] == minK) min_pos = i;
            if(nums[i] == maxK) max_pos = i;

            if(min_pos != -1 && max_pos != -1){
                count += max(0 , min(max_pos,min_pos) - left);
            }
        }

        return count;
    }
};