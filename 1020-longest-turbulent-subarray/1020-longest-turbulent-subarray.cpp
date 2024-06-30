class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int smaller = 1, larger = 1, res = 1, size = arr.size();

        for(int  i =0; i <size-1 ; i++){
            smaller = arr[i] < arr[i+1] ? smaller +1 : 1;
            larger = arr[i] > arr[i+1] ? larger +1 : 1;

            res = max(res, max(smaller,larger));

            swap(smaller,larger);
        }

        return res;
    }
};