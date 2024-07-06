struct node {
    int key,val;
    node * prev, * next; 

    node(){
        key = -1 ;
        val = -1 ;
        prev = nullptr;
        next = nullptr;
    }

    node(int k,int v){
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    
    void remove(node * n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }

    void insert(node * n){
        n->next = head->next;
        n->next->prev = n;
        head->next= n;
        n->prev = head;
    }

public:
    unordered_map<int, node*>map;
    int cap = 0;
    node * head = nullptr;
    node * tail = nullptr;

    LRUCache(int capacity) : cap(capacity) {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        node* current = head;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        node * n = map[key];
        remove(n);
        insert(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            remove(map[key]);
            map.erase(key);
        }
        if(map.size() == cap){
            node * least_recent = tail->prev;
            remove(least_recent);
            map.erase(least_recent->key);
            delete least_recent;
        }
        node * upd = new node(key,value);
        insert(upd);
        map[key] = upd;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */