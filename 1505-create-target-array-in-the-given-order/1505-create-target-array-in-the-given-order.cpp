class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int size = index.size();

        vector<int>res;

        for(int i =0;i < size;i++){
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};