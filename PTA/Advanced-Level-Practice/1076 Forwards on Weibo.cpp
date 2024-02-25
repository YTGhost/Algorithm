#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1010, M = 100010;
int h[N], e[M], ne[M], idx;
int n, l, k;
int st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs(int start)
{
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(start);
    st[start] = 1;
    int level = l;
    int res = 0;
    while(level--) {
        int sz = q.size();
        res += sz;
        while(sz--) {
            int t = q.front();
            q.pop();
            for(int i = h[t]; ~i; i = ne[i]) {
                int val = e[i];
                if(st[val]) continue;
                st[val] = 1;
                q.push(val);
            }
        }
    }
    return res + q.size() - 1;
}

int main()
{
    cin >> n >> l;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        while(m--) {
            int id;
            cin >> id;
            add(id, i);
        }
    }
    cin >> k;
    while(k--) {
        int x;
        cin >> x;
        int res = bfs(x);
        cout << res << endl;
    }
    return 0;
}
