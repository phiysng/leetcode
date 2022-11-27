#include "oj_header.h"

class Solution {
 public:
  /**
   * 字符          数值
   * I             1
   * V             5
   * X             10
   * L             50
   * C             100
   * D             500
   * M             1000
   */
  int romanToInt(string s) { return romanToInt(s, 0); }

  int romanToInt(string& s, int idx) {
    if (s.size() == idx)
      return 0;

    if (s[idx] == 'M')
      return 1000 + romanToInt(s, idx + 1);

    if (s[idx] == 'D')
      return 500 + romanToInt(s, idx + 1);

    if (s[idx] == 'C') {
      if (s.size() > (idx + 1)) {
        if (s[idx + 1] == 'D') {
          return 400 + romanToInt(s, idx + 2);

        } else if (s[idx + 1] == 'M') {
          return 900 + romanToInt(s, idx + 2);
        }
      }
      return 100 + romanToInt(s, idx + 1);
    }

    if (s[idx] == 'L') {
      return 50 + romanToInt(s, idx + 1);
    }

    if (s[idx] == 'X') {
      if (s.size() > (idx + 1)) {
        if (s[idx + 1] == 'L') {
          return 40 + romanToInt(s, idx + 2);

        } else if (s[idx + 1] == 'C') {
          return 90 + romanToInt(s, idx + 2);
        }
      }
      return 10 + romanToInt(s, idx + 1);
    }

    if (s[idx] == 'V') {
      return 5 + romanToInt(s, idx + 1);
    }

    if (s[idx] == 'I') {
      if (s.size() > (idx + 1)) {
        if (s[idx + 1] == 'V') {
          return 4 + romanToInt(s, idx + 2);

        } else if (s[idx + 1] == 'X') {
          return 9 + romanToInt(s, idx + 2);
        }
      }
      return 1 + romanToInt(s, idx + 1);
    }

    return 0;
  }
};
