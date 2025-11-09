#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Time {
public:
    int come, go;
   Time(int a,int b){
        come=a;
        go=b;
    }
};

bool cmp(Time& t1, Time& t2) {
    return t1.go < t2.go;
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("outed.txt", "w", stdout);
    int n;
    cin >> n;
    vector<Time> trains;
    for (int i = 0; i < n; i++) {
        int a, d;
        cin >> a >> d;
        trains.push_back(Time(a, d));
    }
    sort(trains.begin(), trains.end(), cmp);
    vector<int> onstation;
    int platforms = 0;
    for (auto& t : trains) {
        bool found = false;
        for (auto& p : onstation) {
            if (p <= t.come) {
                p = t.go;
                found = true;
                break;
            }
        }
        if (!found) {
            onstation.push_back(t.go);
            platforms++;
        }
    }
    cout << platforms <<endl;
    return 0;
}
