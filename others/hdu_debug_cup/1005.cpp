#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int nu;
    cin >> nu;
    for (int i = 0; i < nu; ++i) {
        string s;
        cin >> s;
        if (s.find("czy") != std::string::npos) {
            printf("ai:czynb!\n");
        } else {
            if (s.find("yjh") != std::string::npos) {
                printf("ai:yjhnb!\n");
            } else {
                printf("ai:no response\n");
            }
        }
    }
}