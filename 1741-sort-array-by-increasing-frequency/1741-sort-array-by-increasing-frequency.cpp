class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int arr[201];

        memset(arr,0,sizeof(arr));

        for(int i : nums){
            arr[i  + 100]++;
        }

        vector<pair<int,int>>pairs;

        for(int i =0; i <= 200 ; i++){
            if(arr[i] >= 1){
                pairs.push_back({arr[i], i - 100});
            }
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        vector<int> res;

        for (const auto& p : pairs) {
            res.insert(res.end(), p.first, p.second);
        }

        return res;
    }
};