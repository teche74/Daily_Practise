class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,vector<int>>>res;

        int size = arr.size();

        for(int i = 0 ; i <size-1; i ++){
            for(int j = i+1; j <size ; j++){
                res.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        sort(res.begin(),res.end());

        return res[k - 1].second;
    }
};