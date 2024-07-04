class Solution {
public:
    int maxRepOpt1(string text) {
        // Step 1: Run-length encoding
        vector<pair<char, int>> rle;
        int size = text.size();
        int prev_ind = 0, count = 1; 
        
        for(int i = 1; i < size; i++) {
            if(text[i] == text[prev_ind]) {
                count++;
            } else {
                rle.push_back({text[prev_ind], count});
                prev_ind = i;
                count = 1;
            }
        }
        rle.push_back({text[prev_ind], count});
        
        unordered_map<char, int> freq;
        for (auto& p : rle) {
            freq[p.first] += p.second;
        }
        
        int maxLength = 0;
        
        for (int i = 0; i < rle.size(); ++i) {
            int currentLength = rle[i].second;
            
            if (freq[rle[i].first] > currentLength) {
                currentLength++;
            }
            
            if (i > 0 && i < rle.size() - 1 && rle[i - 1].first == rle[i + 1].first && rle[i].second == 1) {
                int combinedLength = rle[i - 1].second + rle[i + 1].second;
                if (freq[rle[i - 1].first] > combinedLength) {
                    combinedLength++;
                }
                maxLength = max(maxLength, combinedLength);
            }
            
            maxLength = max(maxLength, currentLength);
        }
        
        return maxLength;
    }
};
