class Node{
    private : 
    
    vector<Node*> links;
    bool end = false;

    public:
    
    Node():links(26, nullptr){};
    
    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void CreateRef(char ch , Node * node){
        links[ch - 'a'] = node;
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        this->end = val;
    }
};

class Trie {
public:
    Node * root = new Node();

    void insert(string word) {
        Node * trav = root;
        for(char ch  : word){
            if(!trav->CheckRef(ch)){
                trav->CreateRef(ch , new Node());
            }
            trav  = trav->GetRef(ch);
        }
        trav->SetEnd(true);
    }
    
    bool search(string word) {
        Node * trav = root;

        for(char ch : word){
            if(!trav->CheckRef(ch)) return false;
            trav = trav->GetRef(ch);
        }
        return trav->IsEnd();
    }
    
    bool startsWith(string prefix) {
        Node * trav = root;

        for(char ch : prefix){
            if(!trav->CheckRef(ch)) return false;
            trav = trav->GetRef(ch);
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