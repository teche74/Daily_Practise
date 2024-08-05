class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string,int>map;

        for(auto t : arr){
            map[t]++;
        }

        for(auto t : arr){
            if(map[t]== 1){
                k--;
                if(k == 0) return t; 
            }
        }
        return  "";
    }
};