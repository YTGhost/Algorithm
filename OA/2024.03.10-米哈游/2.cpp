#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    queue<pair<string, int>> qe;
    map<string, int> name2time;
    map<string, int> name2score;
    int cnt = 0;
    for(int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            string name;
            cin >> name;
            qe.push({name, i});
            name2time[name] = i;
            cnt++;
        } else if(op == 2) {
            string name;
            cin >> name;
            name2time[name] = -1;
            cnt--;
        } else if(op == 3) {
            int x;
            cin >> x;
            while(qe.front().second != name2time[qe.front().first]) {
                qe.pop();
            }
            if(n - x > m) {
                n -= x;
                auto item = qe.front();
                name2score[item.first] += x;
            } else {
                auto item = qe.front();
                name2score[item.first] += n;
                n = 0;
                break;
            }
        } else {
            cout << cnt << endl;
        }
    }
    for(auto item : name2time) {
        cout << item.first << " " << name2score[item.first] << endl;
    }
    return 0;
}