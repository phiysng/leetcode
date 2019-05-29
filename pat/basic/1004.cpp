#include <iostream>

using namespace std;

int main()
{

    int num;
    cin >> num;
    string max_t;
    int max_num = -1;
    string max_record;

    string min_t;
    int min_num = 110;
    string min_record;

    string t;
    int score;
    string record;

    for (int var = 0; var < num; ++var) {
        cin >> t >> record >> score;

        if (score > max_num) {
            max_t = t;
            max_record = record;
            max_num = score;
        }
        if (score < min_num) {
            min_t = t;
            min_record = record;
            min_num = score;
        }
    }
    cout << max_t << " " << max_record << endl;
    cout << min_t << " " << min_record << endl;
}