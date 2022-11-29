class LRUCache {
public:
    int size;
    list<int> l;
    unordered_map<int, pair<list<int>::iterator, int>> m;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        int ret = m[key].second;
        list<int>::iterator pos = m[key].first;
        l.erase(pos);
        l.push_front(key);
        m[key].first = l.begin();
        return ret;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            l.erase(m[key].first);
            l.push_front(key);
            m[key] = {l.begin(), value};
            return;
        }
        if(m.size() < size) {
            l.push_front(key);
            m[key] = {l.begin(), value};
        }
        else {
            int del = l.back();
            m.erase(del);
            l.pop_back();
            l.push_front(key);
            m[key] = {l.begin(), value};
        }
    }
};
