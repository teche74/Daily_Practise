class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int>temp  = original;

        for(int i = 0 ; i <temp.size() ; i++){
            int index =  rand() % temp.size();
            swap(temp[index], temp[i]); 
        }

        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */