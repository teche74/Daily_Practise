class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int>st;
        vector<int>res;
        
        int c_n = 0;
        
        for(int i =0; i <nums.size() ;i++){
            if(nums[i] > 0){
                st.emplace_back(nums[i]);
                c_n = 0;
            }
            else{
                c_n++;
                if(c_n > st.size()) res.emplace_back(-1);
                else res.emplace_back(st[st.size() - c_n]);
            }
        }
        return res;
    }
};