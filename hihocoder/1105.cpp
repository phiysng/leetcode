#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char const* argv[])
{
    int n;
    cin >> n;
    string s;
    int weight;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "A") {
            cin >> weight;
            pq.push(weight);
        } else {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    return 0;
}
