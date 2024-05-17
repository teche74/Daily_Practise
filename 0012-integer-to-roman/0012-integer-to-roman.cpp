class Solution {
public:
    string intToRoman(int num) {
        // unordered_map<char,int>map;

        // map['I'] = 1;
        // map["V"] = 5;
        // map["X"] = 10;
        // map["L"] = 50;
        // map["C"] = 100;
        // map["D"] = 500;
        // map["M"] = 1000;

        // int val = 0;

        // for()

        int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string mark[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int size = sizeof(val)/sizeof(int);

        string res = "";

        for(int i =0 ;i <  size; i++){
            while(num >= val[i]){
                num-=val[i];
                res+=mark[i];
            }
        }

        return res;
    }
};