class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, size = nums.size();

        for(int i  = 0 ; i < size; i++){
            int j =  i+1;
            while(j < size && nums[j] == nums[j-1]){
                j++;
            }
            nums[index++] = nums[i];
            i = j-1;
        }

        return index;
    }
};