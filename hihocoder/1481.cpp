#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        string s;
        cin >> s;
        if (count(s.begin(), s.end(), 'A') >= 2 || s.find("LLL") != string::npos) {
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;
    }
    return 0;
}
