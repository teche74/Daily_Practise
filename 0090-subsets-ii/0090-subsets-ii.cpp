class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        int size = nums.size();
        sort(nums.begin() , nums.end());

        function<void(int)>call =[&](int index){
            res.push_back(temp);
            if(index >= size){
                return;
            }

            for(int i = index; i < size ; i++){
                if(i > index && nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                call(i+1);
                temp.pop_back();
            }
        };


        call(0);

        return res;
    }
};