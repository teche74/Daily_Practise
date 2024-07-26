struct lnk {
    string url;
    lnk *prev;
    lnk *next;

    lnk(std::string s = "") : url(s), prev(nullptr), next(nullptr) {}
} typedef node;

class BrowserHistory {
public:
    node *head;
    node *tail;
    node *current;

    BrowserHistory(std::string homepage) {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        current = new node(homepage);
        head->next = current;
        current->prev = head;
        current->next = tail;
        tail->prev = current;
    }

    void visit(std::string url) {
        node *new_node = new node(url);
        new_node->prev = current;
        new_node->next = tail;
        current->next = new_node;
        tail->prev = new_node;
        current = new_node;
    }

    std::string back(int steps) {
        while (steps-- > 0 && current->prev != head) {
            current = current->prev;
        }
        return current->url;
    }

    std::string forward(int steps) {
        while (steps-- > 0 && current->next != tail) {
            current = current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * std::string param_2 = obj->back(steps);
 * std::string param_3 = obj->forward(steps);
 */
