class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        
        if (s == goal) {
            unordered_set<char> diff(s.begin(), s.end());
            return diff.size() < s.size(); 
        }
        
        vector<int> ind;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                ind.push_back(i);
            }
        }

        if (ind.size() != 2) {
            return false;
        }
        
        int i = ind[0], j = ind[1];
        swap(s[i], s[j]);
        return s == goal;
    }
};