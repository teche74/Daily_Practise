class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0 ,  right  =nums.size()-1, res=  0;

        function<int(int,int)> partition =  [&](int left, int right ){
            int pivot = nums[left] , l = left+1, r = right;

            while(l <= r){
                if(nums[l] < pivot && nums[r] > pivot){
                    swap(nums[l],nums[r]);
                    l++,r--;
                }
                if(nums[l] >= pivot){
                    l++;
                }
                if(nums[r] <= pivot){
                    r--;
                }
            }
            swap(nums[left],nums[r]);
            return r;
        };

        while(true){
            int index  = partition( left, right);

            if(index == k-1){
                res =  nums[index];

                break;
            }
            else if(index < k-1){
                left = index+1;
            }
            else{
                right = index -1;
            }
        }
        return res;
    }
};