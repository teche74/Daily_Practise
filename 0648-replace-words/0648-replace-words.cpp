struct Node{
    Node * links[26];
    bool end = false;

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    void CreateRef(char ch, Node * node){
        links[ch - 'a'] = node;
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};
class Solution {
    Node * root= new Node();
public:
    void Init(vector<string> & strs){
        for(const string  &  str : strs){
            Node * temp = root;

            for(char ch : str){
                if(!temp->CheckRef(ch)){
                    temp->CreateRef(ch, new Node());
                }
                temp = temp->GetRef(ch);
            }
            temp->SetEnd(true);
        }
    }

    string solve(const string &str, Node * node){
        string res = "";

        for(char ch : str){
            if(!node->CheckRef(ch)){
                return "";
            }
            node = node->GetRef(ch);
            res.push_back(ch);
            if(node->IsEnd()) return res;
        }
        return "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Init(dictionary);

        string res = "";

        int low = 0 , high = 0 ,size = sentence.size();

        while(high+1 <= size){
            if(sentence[high+1] == ' '|| high+1 == size){
                string temp = sentence.substr(low, high - low+1);
                low = high+2;
                string get  = solve(temp,root);
                res += (get == "" ? temp : get);
                res.push_back(' ');
            }
            high++;
        }
        res.pop_back();
        return res;
    }
};