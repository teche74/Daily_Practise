class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>pairs;

        for(auto num : nums){
            int mapped_val = 0;
            int place = 1;
            if (num == 0) {
                mapped_val = mapping[0];
            } else {
                int temp = num;
                while (temp > 0) {
                    mapped_val = mapped_val + mapping[temp % 10] * place;
                    temp /= 10;
                    place *= 10;
                }
            }
            cout<<mapped_val<<endl;
            pairs.push_back({mapped_val , num});
        }

        stable_sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        });

        vector<int>res;

        for(auto t : pairs){
            res.emplace_back(t.second);
        }

        return res;
    }
};