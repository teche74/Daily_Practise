class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        int size = nums.size();

        function<void(int)> call = [&](int index){
            if(index >= size){
                res.push_back(temp);
                return;
            }


            call(index+1);
            temp.push_back(nums[index]);
            call(index+1);
            temp.pop_back();
        };

        call(0);
        return res;
    }
};