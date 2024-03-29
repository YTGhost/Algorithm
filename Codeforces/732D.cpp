// https://codeforces.com/problemset/problem/732/D
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> days(n), exams(m);
    for(int i = 0; i < n; i++) {
        cin >> days[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> exams[i];
    }
    function<bool(int)> check = [&](int target) {
        vector<int> lastOccur(m, -1);
        for(int i = 0; i < target; i++) {
            if(days[i] == 0) continue;
            lastOccur[days[i] - 1] = i;
        }
        if(find(lastOccur.begin(), lastOccur.end(), -1) != lastOccur.end()) {
            return false;
        }
        int cnt = 0;
        for(int i = 0; i < target; i++) {
            int idx = days[i] - 1;
            if(idx != -1 && i == lastOccur[idx]) {
                if(exams[idx] > cnt) return false;
                cnt -= exams[idx];
            } else {
                cnt++;
            }
        }
        return true;
    };
    int l = 1, r = n + 1;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << (l == n + 1 ? -1 : l);
    return 0;
}