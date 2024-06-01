struct Node{
    Node * links[26];
    bool end = false;

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void CreateRef(char ch, Node * node){
        links[ch - 'a'] = node;
    }

    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class Trie {
public:
    Node * root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * temp = root;
        for(char ch  : word){
            if(!temp->CheckRef(ch)){
                temp->CreateRef(ch, new Node());
            }
            temp = temp->GetRef(ch);
        }   
        temp->SetEnd(true);    
    }
    
    bool search(string word){
        Node * temp = root;

        for(char ch  : word){
            if(!temp->CheckRef(ch)){
                return false;
            }
            temp = temp->GetRef(ch);
        }   
        return temp->IsEnd();
    }
    
    bool startsWith(string prefix) {
        Node * temp = root;

        for(char ch  : prefix){
            if(!temp->CheckRef(ch)){
                return false;
            }
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