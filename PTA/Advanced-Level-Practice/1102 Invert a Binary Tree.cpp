#include <iostream>
#include <queue>
using namespace std;

int n;
const int N = 15;
int l[N], r[N];
int st[N];

void bfs(int u)
{
    queue<int> q;
    bool flag = false;
    q.push(u);
    while(!q.empty()) {
        int root = q.front();
        q.pop();
        if(flag) cout << " " << root;
        else {
            cout << root;
            flag = true;
        }
        if(l[root] != -1) q.push(l[root]);
        if(r[root] != -1) q.push(r[root]);
    }
    cout << endl;
}

void dfs(int u, bool &flag)
{
    if(u == -1) return;
    dfs(l[u], flag);
    if(flag) cout << " " << u;
    else {
        cout << u;
        flag = true;
    }
    dfs(r[u], flag);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;
        if(a != '-') {
            r[i] = a - '0';
            st[r[i]] = 1;
        } else {
            r[i] = -1;
        }
        if(b != '-') {
            l[i] = b - '0';
            st[l[i]] = 1;
        } else {
            l[i] = -1;
        }
    }
    int root;
    for(int i = 0; i < n; i++) {
        if(st[i] == 0) {
            root = i;
            break;
        }
    }
    bfs(root);
    bool flag = false;
    dfs(root, flag);
    return 0;
}