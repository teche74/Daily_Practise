struct web{
    web * prev = nullptr;
    web * next = nullptr;
    string url = "";

    web(){
        prev = nullptr;
        next = nullptr;
        url = "";
    }

    web(string url){
        prev = nullptr;
        next = nullptr;
        this -> url = url;
    }
};

class BrowserHistory {
public:
    web * head ;
    web * tail ;
    web * curr ;

    BrowserHistory(string homepage) {
        head = new web();
        tail = new web();
        curr = new web(homepage);

        head->next = curr;
        curr->prev = head;
        curr->next = tail;
        tail->prev = curr;  
    }
    
    void visit(string url) {
        web * page  = new web(url);

        page->prev =curr;
        page->next = tail;
        curr->next = page;
        tail->prev = page;
        curr = page;
    }
    
    string back(int steps) {
        while( curr->prev != head && steps > 0){
            steps--;
            curr =curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while( curr->next != tail && steps > 0){
            steps--;
            curr = curr->next;
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