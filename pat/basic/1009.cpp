#include <iostream>
#include<stack>
#include<unordered_map>

using namespace std;


int main(int argc, char *argv[])
{
    string s;
    getline(cin, s);
    string res;
    int begin = 0,  end = s.size() - 1;
    while (s[begin] == ' ') begin++;
    while (s[end] == ' ') end--;
    for (int i = begin; i < end + 1; ++i) {
        if (s[i] == ' ') {
            res = " " +  s.substr(begin, i - begin) + res;
            begin = i + 1;
        }
    }
    res = s.substr(begin, end + 1) + res;
    cout << res;
    return 0;
}