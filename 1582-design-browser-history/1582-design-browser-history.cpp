struct node{
    string val = "";
    node * next = nullptr;
    node * prev = nullptr; 

    node(string s){
        val = s;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
public:
    node * start =nullptr;
    node * tail = nullptr; 
    BrowserHistory(string homepage) {
        node * start = new node(homepage);
        tail = start;
    }
    
    void visit(string url) {
        tail ->next = new node(url);
        tail->next->prev = tail;
        tail = tail->next; 
    }
    
    string back(int steps) {
        while(steps-- && tail -> prev != start){
            tail=tail->prev;
        }
        return tail->val;
    }
    
    string forward(int steps) {
        while(steps-- && tail -> next != nullptr){
            tail=tail->next;
        }
        return tail->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */