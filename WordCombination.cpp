#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    vector<Trie *>nodes;
    bool end = false;

    Trie() : nodes(26, nullptr) , end(false) {}

    bool CheckRef(char ch){
        return nodes[ch - 'a'] != nullptr;
    }

    Trie * GetRef(char ch){
        return nodes[ch - 'a'];
    }

    void CreateRef(char ch , Trie * node){
        nodes[ch - 'a'] = node;
    }

    bool IsEnd(){
        return end;
    }

    void SetEnd(bool val){
        end = val;
    }
};


int main(){
    string input;

    while(cin >> input){
        int size;
        Trie * root = new Trie();
        string dict = "";
        
        auto CreateTrie = [&](string dict){
            Trie * node = root;

            for(char ch : dict){
                if(!node->CheckRef(ch)){
                    node->CreateRef(ch , new Trie());
                }
                node = node->GetRef(ch);
            }
            node->SetEnd(true);
        };

        cin >> size;

        while(size--){
            cin >> dict;
            CreateTrie(dict);
        }

        unordered_map<int,unordered_map<Trie * , int>>dp;

        function<long long(int , Trie *)> Check = [&](int index, Trie * node)->long long{
            if(index >= input.size()) return node->IsEnd();
            if(!node->CheckRef(input[index])) return 0;
        
            if(dp.count(index) && dp[index].count(node)) return dp[index][node];

            node = node->GetRef(input[index]);
            long long ways = 0;

            if(node->IsEnd() ){
                ways = (ways + Check(index+1 , root)) % 1000000007;
            }
            
            ways = (ways + Check(index+1, node)) % 1000000007;
            return dp[index][node] = ways;
        };

        function<void(Trie*)> DeleteTrie = [&](Trie* node) {
            for (auto child : node->nodes)
                if (child) DeleteTrie(child);
            delete node;
        };
        
        long long ways = Check(0, root);
        
        cout<<ways<<endl;
        DeleteTrie(root);
    }
    return 0;
}