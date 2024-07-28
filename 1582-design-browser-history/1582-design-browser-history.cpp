struct history{
    string url = "";
    history * next = nullptr;
    history * prev = nullptr; 

    history(string str = ""){
        url = str;
    }
};

class BrowserHistory {
public:
    history * head, *tail, * curr;

    BrowserHistory(string homepage) {
        head = new history();
        tail = new history();

        curr = new history(homepage);

        head->next = curr;
        curr->prev = head;
        curr->next = tail;
        tail->prev = curr;
    }
    
    void visit(string url) {
        history * new_node = new history(url);
        new_node->prev = curr;
        new_node->next = tail;
        curr->next = new_node;
        tail->prev = new_node;
        curr = new_node;
    }
    
    string back(int steps) {
        while(steps-- > 0 && curr->prev != head){
            curr=curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps-- > 0 && curr->next != tail){
            curr=curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */