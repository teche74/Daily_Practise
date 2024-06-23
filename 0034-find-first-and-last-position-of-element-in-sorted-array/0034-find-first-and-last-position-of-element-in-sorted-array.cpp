class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int  low =  0 , high = 0, size = nums.size();

        for(int i = size ;i >=1 ; i/=2){
            while(low + i < size  && nums[low+i] <target) low+=i;
            while(high + i < size && nums[high+i] <= target) high+=i;
        }

        if(low < size && nums[low] == target) return {low, high};

        if(low + 1 >= size ||  nums[low + 1] != target) return {-1,-1};
        if(nums[low+1] == target && (low +2 < size && nums[low+2] != target) || low+2 >=size) return {low+1, low+1};

        return {low+1, high};

    }
};