#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[])
{
    string in;
    int sum = 0;
    cin >> in;
    for (char i : in) {
        sum += i - '0';
    }
    stack<int> s;
    unordered_map<int, string> map;
    map[0] = "ling";
    map[1] = "yi";
    map[2] = "er";
    map[3] = "san";
    map[4] = "si";
    map[5] = "wu";
    map[6] = "liu";
    map[7] = "qi";
    map[8] = "ba";
    map[9] = "jiu";

    while (sum) {
        s.push(sum % 10);
        sum /= 10;
    }
    while (s.size() > 1) {
        cout << map[s.top()] << " ";
        s.pop();
    }
    cout << map[s.top()] << endl;

    return 0;
}