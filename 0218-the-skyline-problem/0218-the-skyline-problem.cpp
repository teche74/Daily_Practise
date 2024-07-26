class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,pair<int,char>>>vec;

        for(auto t : buildings){
            vec.push_back({t[0] , {t[2] , 's'}});
            vec.push_back({t[1] , {t[2] , 'e'}});
        }

        sort(vec.begin(), vec.end() , [&](pair<int,pair<int,char>> & a , pair<int,pair<int,char>> & b){
            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                if (a.second.second == b.second.second) {
                    if (a.second.second == 's') {
                        return a.second.first > b.second.first; 
                    } else {
                        return a.second.first < b.second.first; 
                    }
                }
                return a.second.second == 's'; 
            }
        });

        multiset<int> cont;

        int prev = 0;
        cont.insert(0);
        vector<vector<int>>res;

        for(auto t : vec){
            if(t.second.second == 's'){
                cont.insert(t.second.first);
            }
            else{
                cont.erase(cont.find(t.second.first));
            }

            int curr = *cont.rbegin();
            if(curr != prev){
                res.push_back({t.first, curr});
                prev=  curr;
            }
        }
        return res;
    }
};