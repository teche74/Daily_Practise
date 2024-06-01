struct Node {
    Node* links[128];
    bool end = false;
    int ind = -1;

    void CreateRef(char ch, Node* node) { links[ch] = node; }

    Node* GetRef(char ch) { return links[ch]; }

    bool CheckRef(char ch) { return links[ch] != nullptr; }

    bool IsEnd() { return end == true; }

    void SetEnd(bool val) { end = val; }
};

class Solution {
    Node* root = new Node();

public:
    void Init(vector<string>& strs) {
        int i = 0;
        for (string str : strs) {
            Node* temp = root;
            for (char ch : str) {
                if (!temp->CheckRef(ch)) {
                    temp->CreateRef(ch, new Node());
                }
                temp = temp->GetRef(ch);
            }
            temp->SetEnd(true);
            temp->ind = i;
            i++;
        }
    }

    bool MatchPattern(string& query, string& pattern) {
        int i = 0, j = 0;
        while (i < query.size() && j < pattern.size()) {
            if (query[i] == pattern[j]) {
                j++;
            } else if (isupper(query[i])) {
                return false;
            }
            i++;
        }
        while (i < query.size()) {
            if (isupper(query[i]))
                return false;
            i++;
        }
        return j == pattern.size();
    }

public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        for (string& query : queries) {
            res.push_back(MatchPattern(query, pattern));
        }
        return res;
    }
};