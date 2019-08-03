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
	int year = 0;
	int day = 0;

	cin >> year >> day;

	vector<int> days{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		days[2]++;
	}

	for (size_t i = 1; i < days.size(); i++)
	{
		if (day > days[i]) {
			day -= days[i];
		}
		else {
			cout << i << endl << day << endl;
			break;
		}
	}
	return 0;
}
