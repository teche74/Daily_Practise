class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        vector<long> candidates;

        candidates.push_back(pow(10, len - 1) - 1);  
        candidates.push_back(pow(10, len) + 1);      


        long prefix = stol(n.substr(0, (len + 1) / 2));

        for (int i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefix + i);
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.push_back(stol(candidate));
        }

        long num = stol(n), closest = -1;
        long minDiff = LONG_MAX;

        for (long candidate : candidates) {
            if (candidate == num) continue;  
            long diff = abs(candidate - num);
            if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                minDiff = diff;
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};