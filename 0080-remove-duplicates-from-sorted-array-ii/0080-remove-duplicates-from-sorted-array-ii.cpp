class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size =  nums.size();

        int index = 0;

        for(int i  = 0 ;i  < nums.size() ; i++){
            if(i >= 2 && nums[i] == nums[index -2 ]){
                continue;
            }
            else    nums[index++] = nums[i];
        }
        return index;
    }
};