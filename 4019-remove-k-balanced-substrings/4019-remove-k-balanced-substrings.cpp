class Solution {
public:
    string removeSubstring(string s, int k) {
        string res;

        for (char c : s) {
            res.push_back(c);

            // Check only when current length >= 2*k
            if (res.size() >= 2 * k) {
                bool match = true;

                // Check if last 2*k chars form "((" + "))"
                for (int i = 0; i < k; i++) {
                    if (res[res.size() - 2 * k + i] != '(') { match = false; break; }
                }
                for (int i = k; i < 2 * k; i++) {
                    if (res[res.size() - 2 * k + i] != ')') { match = false; break; }
                }

                if (match) {
                    res.erase(res.end() - 2 * k, res.end());  // remove last 2*k chars
                }
            }
        }

        return res;
    }
};
