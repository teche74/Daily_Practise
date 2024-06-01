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

class Solution {
    Node * root = new Node();
public:
    void Trie(vector<string> & strs){

        for(const string str : strs){
            Node * temp = root;
            for(char ch : str){
                if(!temp->CheckRef(ch)){
                    temp->CreateRef(ch , new Node());
                }
                temp = temp->GetRef(ch);
            }
            temp->SetEnd(true);
        }
    }

    bool SingleChild(Node * node){
        int count = 0;

        for(int i =0;i < 26 ; i++){
            if(node->links[i] != nullptr){
                count++;

                if(count > 1) return false;
            }
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        Trie(strs);

        Node * temp = root;
        string prefix = "";

        while(temp && !temp->IsEnd() && SingleChild(temp)){
            for(int i =0; i<26 ;i++){
                if(temp->links[i] != nullptr){
                    prefix.push_back(i + 'a');
                    temp = temp->links[i];
                    break;
                }
            }
        }

        return prefix;
    }
};