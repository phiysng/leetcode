#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int nu;
    cin >> nu;
    for (int i = 0; i < nu; ++i) {
        int c;
        cin >> c;

        unordered_set<int> set;
        for (int j = 0; j < c; ++j) {
            int t = 0;
            cin >> t;
            set.insert(t);
        }
        cin >> c;
        int cnt = 0;
        for (int j = 0; j < c; ++j) {
            int l;
            cin >> l;
            set.insert(l);
        }
        cout << set.size() << endl;
    }

    return 0;
}