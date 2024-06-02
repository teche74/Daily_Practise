class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char ,int>map;

        for(char ch : s){
            map[ch]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;

        for(auto t : map){
            pq.push({t.second,t.first});
        }

        string res = "";

        while(pq.size()){
            char ch = pq.top().second;
            int times = pq.top().first;

            while(times--){
                res.push_back(ch);
            }
            pq.pop();
        }

        return res;
    }
};