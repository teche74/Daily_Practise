class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int>squares;

        for(int x : nums){
            squares.push_back(x * x);
        }

        sort(squares.rbegin(), squares.rend());

        int size = nums.size();
        int half = (size & 1 ? (size >> 1) + 1 : (size >> 1));
        long long res = 0;

        for(int i = 0; i < size; i++){
            res += (i < half ? squares[i] : -squares[i]);
        } 

        return res;
    }
};