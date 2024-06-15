class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        int size = nums.size();
        vector<int>res(size,0);

        for(int i =0; i < size ; i++){
            res[i] = nums[nums[i]];
        }

        return res;
    }
};