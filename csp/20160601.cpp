#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<int> a(n);

	for (size_t i = 0; i < a.size(); i++)
	{
		int t = 0;
		cin >> t;
		a[i] = t;
	}

	int res = 0;
	for (int i = 1; i < a.size() - 1; ++i)
	{
		if ((a[i] > a[i - 1] && a[i]> a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
		{
			++res;
		}
	}

	cout << res << endl;

	return 0;
}
