#include "oj_header.h"

class Solution {
public:
	bool validUtf8(vector<int>& data) {
        /// what is valid UTF-8 string
        /// pay attention
        /// 10xx xxxx is invalid , if 1 in the begin , 1 has at least 2
        /// the number of 1 shall match (the number of the rest of the bytes + 1)
        /// 0000 0000-0000 007F | 0xxxxxxx
        //  0000 0080-0000 07FF | 110xxxxx 10xxxxxx
        //  0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
        //  0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

		if (data.empty()) return false;

		int ite = 0; // we have ite bytes that shall belong to this byte.
		for (int i = 0; i < data.size(); ++i) {
			if (ite) {
				--ite;
				if (!validPart(data[i])) {
					return false;
				}
				cout << "1" << endl;
			}
			else
				if ((data[i] & (1 << 7)) == 0) {
					// 一个字节
					cout << "11" << endl;
					continue;
				}
				else
				{
					int ones = 0;
					for (int j = 7; j > 0; --j) {
						if ((data[i] >> j) & 1) {
							ones++;
						}
						else
							break;
					}
					cout << "111" << endl;
					if (ones > 4 || ones <= 1) return false;
					ite = ones - 1;
				}
		}
		return ite == 0;
	}
	bool validPart(int i) {
		return ((i >> 7) & 1) && ((i >> 6) & 1) == 0;
	}
};
