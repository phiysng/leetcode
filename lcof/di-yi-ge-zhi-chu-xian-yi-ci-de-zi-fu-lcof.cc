#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题50. 第一个只出现一次的字符

class Solution
{
public:
	char firstUniqChar(string s)
	{
		/// \todo how to initialize std::array correctly.

		array<int, 1000> _array{};

		for (auto ch : s)
		{
			++_array[ch];
		}


		for (auto ch : s)
		{
			if (_array.at(ch) == 1)
			{
				return ch;
			}
		}

		return ' ';
	}
};
