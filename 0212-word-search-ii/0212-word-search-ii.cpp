class Node {
public:
    Node* links[26];
    string word = "";

    void CreateRef(char ch, Node * node){
        links[ch - 'a' ] = node;
    }

    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool CheckRef(char ch){
        return links[ch - 'a']!= nullptr;
    }

    string GetWord(){
        return word;
    }
};

class Solution {
public:
    Node* root = new Node();

    void Init(vector<string> & strs) {
        
        for (const string& word : strs) {
            Node* node = root;
            for (char c : word) {
                if (!node->CheckRef(c)){
                    node->CreateRef(c, new Node());
                }
                node = node->GetRef(c);
            }
            node->word = word;
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, Node* node, unordered_set<string>& result) {
        char c = board[i][j];
        if (c == '.' || !node->CheckRef(c)) return;
        
        node = node->GetRef(c);
        if (!node->word.empty()) {
            result.insert(node->GetWord());
            node->word = "";
        }

        board[i][j] = '.';
        if (i > 0) dfs(board, i - 1, j, node, result);
        if (j > 0) dfs(board, i, j - 1, node, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, node, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, result);
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Init(words);
        
        unordered_set<string> res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
