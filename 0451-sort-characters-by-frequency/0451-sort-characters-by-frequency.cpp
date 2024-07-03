class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;

        for(auto ch : s){
            map[ch]++;
        }

        priority_queue<pair<int,char>> pq;

        for( auto t : map){
            pq.push(make_pair(t.second,t.first));
        }

        string res = "";

        while(pq.size()){
            char ch = pq.top().second ;
            int  freq = pq.top().first;
            pq.pop();

            while(freq--){
                res.push_back(ch);
            }  
        }

        return res;
    }
};