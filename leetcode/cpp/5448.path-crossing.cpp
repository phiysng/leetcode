#include "oj_header.h"

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};


class Solution {
 public:
  bool isPathCrossing(string path) {

    pair<int, int> pos{0, 0};
    
    unordered_set<pair<int, int>,pair_hash> set{pos};

    for (char c : path) {
      if (c == 'N') {
        pos.second++;
      }
      if (c == 'S') {
        pos.second--;
      }
      if (c == 'E') {
        pos.first++;
      }
      if (c == 'W') {
        pos.first--;
      }
      if (set.find(pos) == set.end())
      {
        set.insert(pos);
      } else
      {
        return true; 
      }
    }
    return false;
  }
};
