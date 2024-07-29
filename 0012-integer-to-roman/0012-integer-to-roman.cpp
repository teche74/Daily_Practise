class Solution {
public:
    string intToRoman(int num) {
        int val[ ] = {1000,900 , 500, 400 ,100 ,90 , 50, 40, 10, 9, 5, 4 ,1};
        string sign[ ]  = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" ,"XL" , "X" ,"IX" , "V", "IV", "I"};

        int size = sizeof(val)/sizeof(int);
        string res= "";

        for(int i = 0 ;i  <size; i++){
            while(num >= val[i]){
                num -=val[i];
                res+=sign[i];
            }

            if(num == 0) break;
        } 

        return res;
    }
};