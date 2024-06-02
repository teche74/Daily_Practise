class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        vector<int>res(size * 2, 0);

        for(int i =0; i <size ; i++){
            int ind1 = i , ind2 = ind1+nums.size();
            cout<<ind1<<" "<<ind2<<endl;
            res[ind1] = nums[i];
            res[ind2] = nums[i];
        }

        return res;
    }
};