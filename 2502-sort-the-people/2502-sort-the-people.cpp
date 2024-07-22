class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> pairs;

        int size = heights.size();

        for(int i =0; i < size ; i++){
            pairs.push_back({heights[i], names[i]});
        }

        sort(pairs.begin(), pairs.end(), [](const pair<int,string>& a , const pair<int, string>  &b ){
            return a.first > b.first;
        });

        vector<string>res;

        for(auto t : pairs){
            res.emplace_back(t.second);
        }

        return res;
    }
};