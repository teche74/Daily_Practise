class Node{
    public:
    int key;
    int val;
    Node * prev = nullptr;
    Node * next = nullptr; 



    Node(int key, int value){
        this->key = key;
        this->val = value;
    }
};

class LRUCache {
public:
    Node * front = nullptr, *end = nullptr;
    int size = 0;
    unordered_map<int , Node*> map;

    void Delete(Node* temp){
        Node * prev = temp->prev;
        Node * next = temp->next;
        prev->next = next;
        next ->prev = prev;
    }

    void Insert(Node * node){
        Node * prev = end ->prev;
        prev->next = node;
        node->prev = prev;
        node->next = end;
        end ->prev = node; 
    }

    LRUCache(int capacity) {
        this->size = capacity;
        front = new Node(-1,-1);
        end = new Node(-1,-1);

        front->next = end;
        end->prev = front;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) return -1;
        Node * node = map[key];
        int value =  node->val;
        
        Delete(node);
        Insert(node);
        return value;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Delete(map[key]);
            Insert(map[key]);
            map[key]->val = value;
        }
        else{
            if(map.size() >= size){
                Node  *temp = front->next;
                Delete(temp);
                map.erase(temp->key);
                delete temp;
            }
            Node * node = new Node(key, value);
            Insert(node);
            map[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */