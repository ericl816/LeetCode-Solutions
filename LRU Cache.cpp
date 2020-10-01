class LRUCache {
public:
    unordered_map<int, list<pair<int, int> >::iterator> ump;
    list<pair<int, int> > lru;
    int size;

    LRUCache (int capacity) {
        ump.clear();
        lru.clear();
        size = capacity;
    }
    
    int get (int key) {
        // Best case time complexity for unordered map::find is O(1) and O(n) worst case
        auto it = ump.find(key);
        int val = -1;
        if (it == ump.end()) return val;
        val = it->second->second;
        lru.erase(it->second);
        ump[key] = lru.insert(lru.begin(), make_pair(key, val));
        return val;
    }
    
    void put (int key, int value) {
        auto it = ump.find(key);
        if (it != ump.end()) {
            lru.erase(it->second);
        } else if (lru.size() == size) {
            ump.erase(lru.back().first);
            lru.pop_back();
        }
        ump[key] = lru.insert(lru.begin(), make_pair(key, value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */