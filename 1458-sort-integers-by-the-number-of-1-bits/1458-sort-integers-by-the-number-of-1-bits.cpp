class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>temp;

        for(int val : arr){
            temp.push_back({__builtin_popcount(val),val});
        }

        sort(temp.begin(),temp.end(), [](const pair<int,int>p1, const pair<int,int>p2){
            if (p1.first != p2.first) 
                return p1.first < p2.first; 
            else 
                return p1.second < p2.second;
        });

        vector<int>res;

        for(auto t : temp){
            res.emplace_back(t.second);
        }

        return res;
    }
};