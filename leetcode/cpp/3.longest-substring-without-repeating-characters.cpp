class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> map;
		int res = 0;
		int beg = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			// 如果此字符不存在
			if (map.find(s[i]) == map.end()) {
				map[s[i]] = i;
				res = max(res, i - beg + 1);
			}
			else {// 此字符已存在

				//在子字符串开始字符之前		
				if (map[s[i]] < beg) {

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
