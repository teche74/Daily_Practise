class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;

        vector<int>res;

        for(int i = size-k ; i < size ; i++){
            res.emplace_back(nums[i]);
        }

        for(int i = 0; i <= size -1 - k ; i++){
            res.emplace_back(nums[i]);
        }

        int index= 0 ;

        for(auto t : res){
            nums[index++] = t;
        }
    }
};