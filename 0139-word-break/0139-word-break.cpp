struct Node{
    Node * links[26];
    bool end = false;

    void CreateRef(char ch , Node * node){
        links[ch - 'a']= node;
    }

    bool CheckRef(char ch){
        return links[ch - 'a'] != nullptr;
    }

    Node * GetRef(char ch){
        return links[ch - 'a'];
    }

    bool IsEnd(){
        return end == true;
    }

    void SetEnd(bool val){
        end = val;
    }
};

class Solution {
public:
    unordered_map<int, bool> map;
    Node * root = new Node();

    void Init(vector<string> & strs){
        for(const string & str : strs){
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

    bool solve(int index, const string & str , Node * node){
        if(index == str.size()) return true;

        if(map.count(index)) return map[index];

        for(int i = index; i < str.size() ; i++){
            if(!node->CheckRef(str[i])) {
                map[index] = false;
                return false;
            }
            node=node->GetRef(str[i]);

            if(node->IsEnd() && solve(i+1,str,root)){
                map[index] = true;
                return true;
            }
        }

        map[index] = false;
        return map[index];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        Init(wordDict);

        Node * temp = root;
        return solve(0,s,temp);
    }
};