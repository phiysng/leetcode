#include "oj_header.h"

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int max_len = 0;

		int start = -1;

		unordered_map<char, int> map;

		for (int i = 0; i < s.size(); ++i)
		{

			if (map.find(s[i]) != map.end())
				start = max(start, map[s[i]]);

			max_len = max<int>(max_len, i - start);
			map[s[i]] = i;
		}
		return max_len;
	}
};

class Solution_v1_1
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int len = 0;
		unordered_map<char, int> map;
		int idx = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (map.find(s[i]) != map.end())
			{
				// exists already
				if (map[s[i]] >= idx)
				{
					// 在子串中已经出现
					idx = map[s[i]] + 1; //新的子串的开始位置 即当前子串出现的位置的后一个位置
				}
			}
			len = max<int>(len, i - idx + 1);
			map[s[i]] = i;
		}

		return len;
	}
};

//更直观的版本
class Solution_v2
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> map;
		int res = 0;
		int beg = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			// 如果此字符不存在
			if (map.find(s[i]) == map.end())
			{
				map[s[i]] = i;
				res = max(res, i - beg + 1);
			}
			else
			{ // 此字符已存在

				//在子字符串开始字符之前
				if (map[s[i]] < beg)
				{
				}
				//在开始字符之后
				else
				{
					beg = map[s[i]] + 1;
				}
				map[s[i]] = i;
				res = max(res, i - beg + 1);
			}
		}
		return res;
	}
};
