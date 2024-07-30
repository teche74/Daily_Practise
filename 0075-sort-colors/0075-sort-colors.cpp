class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // function<void(void)> approach1 = [&](){
        //     int count_z = 0 , count_one = 0 ,size = nums.size();

        //     for(int i = 0; i < size; i++){
        //         count_z +=(nums[i] == 0);
        //         count_one  += (nums[i] == 1);
        //     }

        //     for(int i =0; i < nums.size(); i++){
        //         if(count_z > 0){
        //             nums[i] = 0;
        //             count_z--;
        //         }
        //         else if(count_one > 0){
        //             nums[i] = 1;
        //             count_one--;
        //         }
        //         else{
        //             nums[i] = 2;
        //         }
        //     }
        // };

        // approach1();


        // dutch national flag algo

        int low = 0 , mid = 0 , high = nums.size()-1;

        while(mid<= high){
            if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        } 
    }
};