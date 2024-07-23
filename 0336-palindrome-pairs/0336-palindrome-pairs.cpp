struct node{
    node *links[26];
    bool end = false;
    int index = -1;

    bool CheckRef(char ch){
        return links[ch - 'a']!= nullptr;
    }

    node* GetRef(char ch){
        return links[ch- 'a'];
    }

    void CreateRef(char ch, node * n){
        links[ch - 'a'] = n;
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }

    int GetInd(){
        return index;
    }

    void SetInd(int val){
        index = val;
    }
};
class Solution {
    node * root = new node();
public:
    void searchWords(node* temp, vector<int>& indices) {
        if (temp->IsEnd()) {
            indices.push_back(temp->GetInd());
        }
        for (int i = 0; i < 26; ++i) {
            if (temp->links[i] != nullptr) {
                searchWords(temp->links[i], indices);
            }
        }
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
       auto Init = [&](){
            int index=0;
            for(const string  & str : words){
                node * temp = root;
                for(int i = str.size()-1 ;i >= 0 ; i--){
                    if(!temp->CheckRef(str[i])){
                        temp->CreateRef(str[i], new node());
                    }
                    temp = temp->GetRef(str[i]);
                }
                temp->SetEnd(true);
                temp->SetInd(index);
                index++;
            }
       };  

       Init();

       vector<vector<int>>res;

       auto Palli = [](const string& str, int left, int right) {
            while (left < right) {
                if (str[left++] != str[right--]) return false;
            }
            return true;
        };

       
       for (int i = 0; i < words.size(); ++i) {
            
            const string& word = words[i];
            node* trav = root;
            
            for (int j = 0; j < word.size(); ++j) {
            
                if (trav->IsEnd() && trav->GetInd() != i && Palli(word, j, word.size() - 1)) {
                    res.push_back({i, trav->GetInd()});
                }
                if (!trav->CheckRef(word[j])) {
                    trav = nullptr;
                    break;
                }
                trav = trav->GetRef(word[j]);
            }
            
            if (trav == nullptr) continue;
            
            vector<int> indices;
            searchWords(trav, indices);
            for (int ind : indices) {
                if (i != ind && Palli(words[ind], 0, words[ind].size() - word.size() - 1)) {
                    res.push_back({i, ind});
                }
            }
        }

        return res;
    }
};