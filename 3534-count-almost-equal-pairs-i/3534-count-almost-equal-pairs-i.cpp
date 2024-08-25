class Solution {
public:
    bool check(int a , int b){
        string str = to_string(a);
        string ptr = to_string(b);

        while(str.length() < ptr.length()) str =  "0" + str;
        while(ptr.length() < str.length()) ptr = "0" + ptr;

        int diff = 0 , ind1 =-1 , ind2=-1 ,size = str.size();

        for(int i = 0; i < size; i++){
            if(str[i] != ptr[i]){
                diff++;
                if(ind1 == -1) ind1 = i;
                else if(ind2 == -1 ) ind2  = i; 
                else return false;
            }
        }

        if(diff == 2){
            swap(str[ind1], str[ind2]);
        }

        return str == ptr;
    }
    int countPairs(vector<int>& nums) {
        int size= nums.size();

        int res= 0;

        for(int i = 0 ; i < size ; i++){
            for(int j = i+1; j < size; j++){
                if(nums[i] == nums[j] || check(nums[i], nums[j])) res++; 
            }
        }   

        return res;
    }
};