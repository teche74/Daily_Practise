class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();

        int c_z = 0 , c_o = 0;

        for(int i = 0 ;i  < size;  i ++){
            if(nums[i] == 0){
                c_z++;
            }
            else if(nums[i] == 1){
                c_o++;
            }
        }

        for(int i = 0 ; i < size; i++){
            if(c_z){
                nums[i] = 0;
                c_z--;
            }
            else if(c_o){
                nums[i] = 1;
                c_o--;
            }
            else{
                nums[i] = 2;
            }
        }


    }
};