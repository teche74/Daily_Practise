class RandomizedSet {
public:
    vector<int>vals;
    unordered_map<int,int>map;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(map.find(val) == map.end()){
            vals.emplace_back(val);
            map[val] = vals.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;
        
        int last_index = vals.size()-1;
        int target_index = map[val];

        swap(vals[last_index] , vals[target_index]);
        map[vals[target_index]] = target_index;
        map.erase(vals[last_index]);
        vals.pop_back();
        return true;
    }
    
    int getRandom() {
        return vals[rand() % map.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */