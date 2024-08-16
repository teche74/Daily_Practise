class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int cap) {
        sort(arr.begin(), arr.end(), [](vector<int> & a  , vector<int> & b){
            return a[1] > b[1]; 
        });

        int size = arr.size() , res = 0;

        for(int i = 0 ; i < size ; i++){
            int no_of_boxes = arr[i][0];
            int units = arr[i][1];

            if(cap >= no_of_boxes){
                res += (no_of_boxes * units);
                cap-=no_of_boxes;
            }   
            else{
                res += cap * units;
                break;
            }
        }
        return res;
    }
};