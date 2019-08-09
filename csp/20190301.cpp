#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int
main(int argc, char const* argv[])
{
	int n;
	cin >> n;
	vector<int> v(n);

	for (size_t i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		v[i] = t;
	}

	int m_ = v.front();
	int n_ = v.back();

	if (m_ < n_) swap(m_, n_);

	double mid = 0;

	if (n % 2) {
		mid = v[n / 2];
	}
	else {
		mid = (1.0 * v[n / 2 - 1] + v[n / 2]) / 2;
	}
	if (mid == (int)mid) {
		printf("%d %.0f %d\n", m_, mid + 0.0, n_);
	}
	else
		printf("%d %.1f %d\n", m_, mid + 0.0, n_);

	return 0;
}
