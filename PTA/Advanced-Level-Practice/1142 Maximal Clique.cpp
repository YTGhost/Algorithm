#include <iostream>
#include <cstring>
using namespace std;

const int N = 205;
int n, m;
int st[N];
int g[N][N];
int nodes[N];

bool checkClique(int k)
{
    for(int i = 0; i < k-1; i++)
        for(int j = i + 1; j < k; j++) {
            if(!g[nodes[i]][nodes[j]]) return false;
        }
    return true;
}

bool checkMaxClique(int k)
{
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            bool flag = true;
            for(int j = 0; j < k; j++) {
                if(!g[i][nodes[j]]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    int cnt;
    cin >> cnt;
    while(cnt--) {
        int k;
        cin >> k;
        memset(st, 0, sizeof st);
        for(int i = 0; i < k; i++) {
            cin >> nodes[i];
            st[nodes[i]] = 1;
        }
        if(checkClique(k)) {
            if(checkMaxClique(k)) {
                cout << "Yes" << endl;
            } else cout << "Not Maximal" << endl;
        } else {
            cout << "Not a Clique" << endl;
        }
    }
    return 0;
}