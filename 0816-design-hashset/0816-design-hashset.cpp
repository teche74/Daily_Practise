class MyHashSet {
public:
    int size =1000;
    vector<list<int>>table;

    MyHashSet(int initialSize = 1000) : size(initialSize), table(initialSize) {}

    int hash_func(int key){
        return key % size;
    }
    
    void add(int key) {
        int hash_ind = hash_func(key);
        auto& cell = table[hash_ind];
        for (int element : cell) {
            if (element == key) {
                return; 
            }
        }
        cell.push_back(key);
    }
    
    void remove(int key) {
        int hash_ind = hash_func(key);
        auto& cell = table[hash_ind];
        cell.remove(key);
    }
    
    bool contains(int key) {
        int hash_ind = hash_func(key);
        auto& cell = table[hash_ind];
        for (int element : cell) {
            if (element == key) {
                return true;
            }
        }
        return false; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */