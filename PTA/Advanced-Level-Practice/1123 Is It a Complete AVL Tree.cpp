#include <iostream>
#include <queue>
using namespace std;

const int N = 25;
int l[N], r[N], v[N], h[N], idx, pos[N];
int n;

void update(int u)
{
    h[u] = max(h[l[u]], h[r[u]]) + 1;
}

void L(int &u)
{
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}

void R(int &u)
{
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}

int get_balance(int u)
{
    return h[l[u]] - h[r[u]];
}

void insert(int &u, int x)
{
    if(!u) u = ++idx, v[u] = x;
    else if(x < v[u]) {
        insert(l[u], x);
        if(get_balance(u) == 2) {
            if(get_balance(l[u]) == 1) {
                R(u);
            } else {
                L(l[u]), R(u);
            }
        }
    } else {
        insert(r[u], x);
        if(get_balance(u) == -2) {
            if(get_balance(r[u]) == -1) {
                L(u);
            } else {
                R(r[u]), L(u);
            }
        }
    }
    update(u);
}

bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    pos[u] = 1;
    string res;
    bool flag = true;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(pos[t] > n) flag = false;
        res += to_string(v[t]) + " ";
        if(l[t]) q.push(l[t]), pos[l[t]] = pos[t] * 2;
        if(r[t]) q.push(r[t]), pos[r[t]] = pos[t] * 2 + 1;
    }
    res.pop_back();
    cout << res << endl;
    return flag;
}

int main()
{
    int root = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }
    
    bool res = bfs(root);
    if(res) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}