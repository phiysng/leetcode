#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct info {
    string s_;
    int score_;
    int nu_;
    info(string s, int score, int nu)
        : s_(s)
        , score_(score)
        , nu_(nu)
    {
    }
};
struct all_score {

    double t_;
    double a_;
    double b_;
    int n = 0;
    all_score(double t = 0, double a = 0, double b = 0)
        : t_(t)
        , a_(a)
        , b_(b)
    {
    }
};

int main(int argc, char* argv[])
{
    int n;
    cin >> n;
    unordered_map<string, all_score> scores;
    for (int i = 0; i < n; ++i) {
        string id;
        double score;
        string school;
        cin >> id >> score >> school;
        std::transform(school.begin(), school.end(), school.begin(), ::tolower);
        if (scores.find(school) == scores.end()) { //don't exist
            scores[school] = all_score(0, 0, 0);
        }
        if (id[0] == 'T') {
            scores[school].t_ += score;
        }
        if (id[0] == 'A') {
            scores[school].a_ += score;
        }
        if (id[0] == 'B') {
            scores[school].b_ += score;
        }
        ++scores[school].n;
    }
    vector<info> res;
    for (auto i : scores) {
        res.push_back(info(i.first, (int)(i.second.t_ * 1.5 + i.second.a_ + 1.0 * i.second.b_ / 1.5),
            i.second.n));
    }
    sort(res.begin(), res.end(), [](info a, info b) {
        if (a.score_ == b.score_) {
            if (a.nu_ == b.nu_) {
                return a.s_ < b.s_;
            } else {
                return a.nu_ < b.nu_;
            }
        } else
            return a.score_ > b.score_;
    });
    printf("%zu\n", res.size());
    vector<int> rank(res.size());
    rank[0] = 1;
    for (int i = 1; i < res.size(); ++i) {
        if (res[i].score_ == res[i - 1].score_)
            rank[i] = rank[i - 1];
        else
            rank[i] = i + 1;
    }
    //cout << 1 << " " << res[0].s_ << " " << res[0].score_ << " " << res[0].nu_ << endl;
    for (int i = 0; i < res.size(); ++i) {

        cout << rank[i] << " " << res[i].s_ << " " << res[i].score_ << " " << res[i].nu_ << endl;
    }

    return 0;
}