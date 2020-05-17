class LRUCache {
public:
    map<int, int> mp;
    list<int> lst;
    int size;
    LRUCache (int capacity) {
        mp.clear();
        lst.clear();
        size = capacity;
    }
    
    int get (int key) {
        if (mp.find(key) == mp.end()) return -1;
        else {
            lst.remove(key);
            lst.push_back(key);
            return mp[key];
        }
    }
    
    void put (int key, int value) {
        if (lst.size() >= size) {
            if (mp.find(key) != mp.end()) {
                lst.remove(key);
            }
            else {
                mp.erase(lst.front());
                lst.pop_front();
            }
        }
        else {
            if (mp.find(key) != mp.end()) {
                lst.remove(key);
            }
        }
        mp[key] = value;
        lst.push_back(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */