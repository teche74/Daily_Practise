class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_of_all = 0;

        int first = 0 , second = 0 , set_bit = 0;

        for(auto t : nums){
            xor_of_all ^= t; 
        } 

        for(int i = 0; i <32 ;i ++){
            if(xor_of_all & (1 << i)){
                set_bit = 1 <<i;
                break;
            }
        }

        for(auto t : nums){
            if(t & set_bit){
                first ^= t;
            }
        }

        second = xor_of_all ^ first;

        return {first, second};
    }
};