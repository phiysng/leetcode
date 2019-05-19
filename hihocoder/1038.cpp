#include <iostream>
#include<vector>
#include <unordered_map>
#include<algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
	int nu, values;
	cin >> nu >> values;
	vector<int> need(nu + 1), value(nu + 1);
	for (size_t i = 1; i < nu + 1; i++)
	{
		cin >> need[i] >> value[i];

	}

	vector<vector<int>> res(nu + 1, vector<int>(values + 1));

	for (int i = 1; i < res.size(); ++i) {// 1-> nu+1
		for (int val = 0; val <= values; ++val) {
			res[i][val] = res[i - 1][val];
			if (val - need[i] >= 0)
				res[i][val] = max(res[i][val], res[i - 1][val - need[i]] + value[i]);
		}
	}

	cout << res[nu][values] << endl;
	return 0;
}
