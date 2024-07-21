class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low = 0 , high= nums.size()-1;
        int size = nums.size();
        vector<int>temp = nums;

        int ind1 = -1, ind2  =-1;
        sort(temp.begin(), temp.end());

        while (low < size && nums[low] == temp[low]) {
            low++;
        }

        while (high > low && nums[high] == temp[high]) {
            high--;
        }

        return high - low + 1;
    }
};