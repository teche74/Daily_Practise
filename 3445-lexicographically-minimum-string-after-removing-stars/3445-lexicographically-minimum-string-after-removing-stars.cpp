class Solution {
public:
    string clearStars(string s) {

        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; 
            }
            return a.second < b.second; 
        };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            }
            if (s[i] == '*') {
                if (!pq.empty()) {
                    s[pq.top().second] = '#';
                    pq.pop();
                }
                s[i] = '#';
            }
        }

        string result;
        for (char c : s) {
            if (c != '#') {
                result.push_back(c);
            }
        }

        return result;
    }
};
