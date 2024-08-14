class BrowserHistory {
private:
    struct Web {
        string url;
        unique_ptr<Web> next;
        Web* prev;

        Web(string url){
            this->url = url;
            prev = nullptr;
            next = nullptr;
        }
    };

    unique_ptr<Web> head;
    Web* tail;
    Web* curr;

public:
    BrowserHistory(string homepage) {
        head = make_unique<Web>(homepage);
        tail = head.get();
        curr = head.get();
    }
    
    void visit(string url) {
        auto newPage = make_unique<Web>(url);
        newPage->prev = curr;
        curr->next = move(newPage);
        curr = curr->next.get();
        tail = curr;  
    }
    
    string back(int steps) {
        while(curr->prev != nullptr && steps > 0) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next != nullptr && steps > 0) {
            curr = curr->next.get();
            steps--;
        }
        return curr->url;
    }
};
