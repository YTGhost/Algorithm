#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int N = 10100;
struct Item {
    int id, cnt, score;
    
    bool operator< (const Item& t) const {
        if(score != t.score) return score > t.score;
        else if(cnt != t.cnt) return cnt < t.cnt;
        else return id < t.id;
    }
};
int n;
int p[N], cnt[N], s[N];
unordered_map<int, int> totalMap;
unordered_set<int> personSet;
unordered_map<int, int> st;
vector<Item> res;

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n;
    for(int i = 0; i < N; i++)  p[i] = i, cnt[i] = 1;
    vector<int> person(n);
    vector<vector<int>> teammates;
    for(int i = 0; i < n; i++) {
        int id, k, score;
        cin >> id >> k;
        personSet.insert(id);
        vector<int> temp;
        for(int j = 0; j < k; j++) {
            int teammate;
            cin >> teammate;
            personSet.insert(teammate);
            temp.push_back(teammate);
        }
        cin >> score;
        s[id] = score;
        person[i] = id;
        teammates.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        int id = person[i];
        vector<int> temp = teammates[i];
        for(auto teammate : temp) {
            int t1 = find(id), t2 = find(teammate);
            if(t1 == t2) continue;
            if(t1 < t2) p[t2] = t1, cnt[t1] += cnt[t2], s[t1] += s[t2];
            else p[t1] = t2, cnt[t2] += cnt[t1], s[t2] += s[t1];
        }
    }
    for(auto person : personSet) {
        if(p[person] == person) {
            res.push_back({person, cnt[person], s[person]});
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl; 
    for(auto t : res) {
        printf("%04d %d %d\n", t.id, t.cnt, t.score);
    }
    return 0;
}