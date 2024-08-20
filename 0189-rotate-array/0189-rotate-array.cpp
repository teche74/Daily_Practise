class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();

        k %= size;

        vector<int>temp;

        for(int i = size-k ; i < size ; i++){
            temp.emplace_back(nums[i]);
        }

        for(int i = 0 ;i < size - k; i++){
            temp.emplace_back(nums[i]);
        }

        for(int i  =0 ; i < size; i ++){
            nums[i]  =temp[i];
        }
    }
};