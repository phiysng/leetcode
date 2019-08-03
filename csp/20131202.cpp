#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int a, b, c;
	char d;
	scanf("%d-%d-%d-%c", &a, &b, &c, &d);

	vector<int> digits(9);
	string isbn = to_string(a) + to_string(b) + to_string(c);

	int code = 0;
	for (size_t i = 1; i < 10; i++)
	{
		code += (isbn[i - 1] - '0') * i;
	}
	code = code % 11;

	if (code + '0' == d || (code == 10 && d == 'X')) {
		cout << "Right" << endl;
	}
	else {
		char c_ = '0' + code;
		if (code == 10) {
			c_ = 'X';
		}
		cout << to_string(a) + "-" + to_string(b) + "-" + to_string(c) + "-" + c_ << endl;
	}

	return 0;
}
