class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int size = nums.size();
        int first_pos  = size;
        int first_neg = -1;

        for(int i = size ; i>= 1 ;i/=2){
            while(first_pos - i >= 0 && nums[first_pos - i]  > 0){
                first_pos-=i;
            }

            while(first_neg+ i < size && nums[first_neg + i] < 0){
                first_neg+=i;
            }
        }

        return max(first_neg+1 , size - first_pos );
    }
};