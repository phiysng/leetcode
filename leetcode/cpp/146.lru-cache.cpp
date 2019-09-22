class LRUCache {
public:
    LRUCache(int capacity)
    {
        this->cap = capacity;
    }

    int get(int key)
    {
        auto it = map.find(key);
        if (it == map.end())
            return -1;

        // key exists
        auto kv = *map[key];

        cache.erase(map[key]);
        cache.push_front(kv);

        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value)
    {
        auto it = map.find(key);
        if (it == map.end()) {
            //不存在
            //容量已满时 删除最后一个节点
            if (cache.size() == cap) {
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            //已存在
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }

private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map; //到链表的映射
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */