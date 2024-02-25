#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
typedef pair<string, string> PII;

int main()
{
    vector<PII> res;
    vector<PII> come;
    cin >> n;
    unordered_map<string, int> mp;
    unordered_map<string, int> comeMp;
    for(int i = 0; i < n; i++) {
        string id;
        cin >> id;
        mp[id]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        string id;
        cin >> id;
        if(mp.count(id)) comeMp[id]++;
        come.push_back({ id.substr(6, 8), id });
    }
    for(auto item : comeMp) {
        res.push_back({ item.first.substr(6, 8), item.first });
    }
    sort(res.begin(), res.end());
    sort(come.begin(), come.end());
    cout << res.size() << endl;
    if(res.size()) {
        cout << res[0].second << endl;
    } else {
        cout << come[0].second << endl;
    }
    return 0;
}