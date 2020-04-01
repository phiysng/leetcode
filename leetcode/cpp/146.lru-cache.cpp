#include <queue>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }

        int value = map[key]->second;
        // update to the front of the list.

        l.erase(map[key]);

        l.push_front(make_pair(key, value));
        map[key] = l.begin();
        return value;
    }

    void put(int key, int value)
    {
        // if exists delete old
        if (map.find(key) != map.end())
        {
            l.erase(map[key]);
            l.push_front(make_pair(key, value));
            map[key] = l.begin();
        }

        //delete the last node if cap is maximun.
        if (l.size() >= cap)
        {
            pair<int, int> back = l.back();
            map.erase(back.first);
            l.pop_back();
        }

        l.push_front((make_pair(key, value)));
        map[key] = l.begin();
    }

private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */