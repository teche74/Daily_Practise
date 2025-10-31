class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();

        function<int(int, int)>found = [&](int val , int high){
            int low = 0 ;
            while(low <= high){
                int mid = low + ((high - low) >> 1);

                if(numbers[mid] == val) return mid;

                else if(numbers[mid] > val) high = mid-1;
                else low = mid+1;
            }

            return -1;
        };
        for(int i = 0; i < size; i++){
            int val = target - numbers[i];

            int index = found(val , i-1);
            if(index != -1){
                return {index+1 , i+1};
            }
        }

        return {-1,-1};
    }
};