#include <iostream>
using namespace std;

const int N = 25;
int l[N], r[N], v[N], h[N], idx;

void update(int u)
{
    h[u] = max(h[l[u]], h[r[u]]) + 1;
}

void R(int& u)
{
    int p = l[u];
    l[u] = r[p], r[p] = u;
    update(u), update(p);
    u = p;
}

void L(int &u)
{
    int p = r[u];
    r[u] = l[p], l[p] = u;
    update(u), update(p);
    u = p;
}

int get_balance(int u)
{
    return h[l[u]] - h[r[u]];
}

void insert(int& u, int x)
{
    if(!u) u = ++idx, v[u] = x;
    else if(x < v[u]) {
        insert(l[u], x);
        if(get_balance(u) == 2) {
            if(get_balance(l[u]) == 1) R(u);
            else L(l[u]), R(u);
        }
    } else {
        insert(r[u], x);
        if(get_balance(u) == -2) {
            if(get_balance(r[u]) == -1) L(u);
            else R(r[u]), L(u);
        }
    }
    update(u);
}

int main()
{
    int n, root = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }
    
    cout << v[root] << endl;
    return 0;
}