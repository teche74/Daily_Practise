class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int digi_sum = 0;

        for(auto t : nums){
            string str = to_string(t);

            for(char ch : str){
                digi_sum+=(ch - '0');
            }
        }

        return abs(sum - digi_sum);

    }
};