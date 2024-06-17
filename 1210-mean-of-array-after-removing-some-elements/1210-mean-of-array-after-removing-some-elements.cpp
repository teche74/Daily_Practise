class Solution {
public:
    double trimMean(vector<int>& arr) {
        int size = arr.size();
        sort(arr.begin(),arr.end());

        int ele = size *0.05;

        int val= accumulate(arr.begin()+ele,arr.end()-ele , 0);

        int count = size - (ele*2);

        return (double)val/count;
    }
};