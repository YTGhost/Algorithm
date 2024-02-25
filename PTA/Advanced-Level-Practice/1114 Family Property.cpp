#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10010;
int p[N], c[N], hc[N], ha[N];
bool st[N];
int n;

struct Edge{
    int a, b;
}edges[N];

struct Family{
    int id, cnt, hc, ha;
    
    bool operator< (const Family& t) const {
        if(ha * t.cnt != t.ha * cnt) return ha * t.cnt > t.ha * cnt;
        return id < t.id;
    }
};

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n;
    int m = 0;
    for(int i = 0; i < n; i++) {
        int id, father, mother, k;
        cin >> id >> father >> mother >> k;
        st[id] = true;
        if(father != -1) edges[m++] = {id, father};
        if(mother != -1) edges[m++] = {id, mother};
        while(k--) {
            int son;
            cin >> son;
            edges[m++] = {id, son};
        }
        cin >> hc[id] >> ha[id];
    }
    
    for(int i = 0; i < N; i++) p[i] = i, c[i] = 1;
    
    for(int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b;
        st[a] = true, st[b] = true;
        int pa = find(a), pb = find(b);
        if(pa != pb) {
            if(pb > pa) swap(pa, pb);
            c[pb] += c[pa];
            hc[pb] += hc[pa];
            ha[pb] += ha[pa];
            p[pa] = pb;
        }
    }
    
    vector<Family> families;
    for(int i = 0; i < N; i++) {
        if(st[i] && p[i] == i) {
            families.push_back({i, c[i], hc[i], ha[i]});
        }
    }
    sort(families.begin(), families.end());
    cout << families.size() << endl;
    for(auto f : families) {
        printf("%04d %d %.3lf %.3lf\n", f.id, f.cnt,(double) f.hc / f.cnt, (double)f.ha / f.cnt);
    }
    return 0;
}