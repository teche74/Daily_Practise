class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,pair<int,char>>>points;

        for(auto t : buildings){
            points.push_back({t[0] , {t[2] , 's'}}); // left,height , start
            points.push_back({t[1] , {t[2] , 'e'}}); // right,height , end
        }

        sort(points.begin(),points.end(),[&](pair<int,pair<int,char>> & a , pair<int,pair<int,char>> & b){

            // ek case ye he ki agr do buildings ka start same he to higher height valid building phle rkhi jayegi 
            // ek case ye he jab dono building ke end same hon to phle choti building ayegi taki usko consider na kre.
            // agr meri phli building ka end overlap krega agli building ke start ko (is time hum phle second building ka start lenge)
            

            if (a.first != b.first) {
                return a.first < b.first;
            } else {
                if (a.second.second == b.second.second) {
                    if (a.second.second == 's') {
                        return a.second.first > b.second.first; // for starts, higher height first
                    } else {
                        return a.second.first < b.second.first; // for ends, lower height first
                    }
                }
                return a.second.second == 's'; // if one is start and the other is end, start goes first
            }
        });

        multiset<int> heights;
        heights.insert(0);
        int prevHeight = 0;
        vector<vector<int>> res;

        for (auto t : points) {
            int x = t.first;
            int h = t.second.first;
            char type = t.second.second;

            if (type == 's') {
                heights.insert(h);
            } else {
                heights.erase(heights.find(h));
            }

            int currentHeight = *heights.rbegin();
            if (currentHeight != prevHeight) {
                res.push_back({x, currentHeight});
                prevHeight = currentHeight;
            }
        }

        return res;

    }
};