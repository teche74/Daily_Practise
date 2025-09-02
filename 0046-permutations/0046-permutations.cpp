class Solution {
public:
    void __perm(vector<int> & nums){
        int size = nums.size();

        int index = -1;

        for(int i = size-2 ; i >= 0 ; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin(),  nums.end());
            return;
        }

        for(int i = size-1 ; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i] , nums[index]);
                break;
            }
        }

        reverse(nums.begin() + index +1 , nums.end());
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        res.push_back(nums);
        while(true){
            __perm(nums);
            if(nums == res[0])break;
            
            res.push_back(nums);
        }
        return res;
    }
};