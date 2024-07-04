class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<int>> indices(26);

        int size = text.size();

        for (int i = 0; i < size; ++i) {
            indices[text[i] - 'a'].push_back(i);
        }

        int res = 1;

        for (int k = 0; k < 26; ++k) {
            if (indices[k].empty()) continue;

            int cnt = 1, extras = 0, max_count = 0;

            for (int i = 1; i < indices[k].size(); ++i) {
                if (indices[k][i] == indices[k][i - 1] + 1) {
                    cnt++;
                } else {
                    extras = (indices[k][i] == indices[k][i - 1] + 2) ? cnt : 0;
                    cnt = 1;
                }
                max_count = max(max_count, cnt + extras);
            }
            res = max(res, max_count + ((indices[k].size() > max_count) ? 1 : 0));
        }

        return res;
    }
};
