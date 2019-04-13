#include <iostream>
#include<stack>
#include<unordered_map>
#include<cstdio>

using namespace std;

int main(int argc, char *argv[])
{
    int a, b, c;
    int num = 1;
    int n;
    cin >> n;
    for (int var = 0; var < n; ++var) {
        cin >> a >> b >> c;
        if (a + b - c > 0)
            printf("Case #%d: true\n", num++);
        else
            printf("Case #%d: false\n", num++);

    }

    return 0;
}