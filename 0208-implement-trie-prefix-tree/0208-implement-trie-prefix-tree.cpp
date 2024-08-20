struct node{
    node * links[26];
    bool end = false;


    void CreateRef(char ch, node * t){
        links[ch - 'a'] = t;
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    node *  GetRef(char ch){
        return links[ch -  'a'];
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class Trie {
    node * root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node * temp = root;
        for(char ch : word){
            if(!temp->CheckRef(ch)){
                temp->CreateRef(ch, new node());
            }
            temp  =temp->GetRef(ch);
        }
        temp->SetEnd(true);
    }
    
    bool search(string word) {
        node  * temp  =root;

        for(char ch : word){
            if(!temp->CheckRef(ch)) return false;
            temp = temp->GetRef(ch);
        }
        return temp->IsEnd();
    }
    
    bool startsWith(string prefix) {
        node * temp = root;
        for(char ch  : prefix){
            if(!temp->CheckRef(ch)) return false;
            temp = temp->GetRef(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */