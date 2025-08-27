class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort and find  -> nlogn

        sort(nums.begin() , nums.end());

        int max_range = 1 , length = 1;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+1){
                length++;
            }
            else{
                length =1; 
            }

            max_range= max(max_range , length);
        }

        return nums.empty() ? 0 : max_range;
    }
};