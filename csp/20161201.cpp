#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;



int main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		v[i] = t;
	}

	sort(v.begin(), v.end());

	int mid = v[(v.size()) / 2];

	int lt = 0;
	int mt = 0;
	for (auto& a : v) {
		if (a > mid)++mt;
		if (a < mid) ++lt;
	}


	if (lt ==mt) {
		cout << mid << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
