#include <iostream>
#include <cstring>
using namespace std;

int n, m;
const int N = 10010;
int st[N];

struct edge {
    int a;
    int b;
} edges[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> edges[i].a >> edges[i].b;
    }
    int k;
    cin >> k;
    while(k--) {
        int cnt;
        cin >> cnt;
        memset(st, 0, sizeof st);
        while(cnt--) {
            int x;
            cin >> x;
            st[x] = 1;
        }
        
        int idx = 0;
        for(; idx < m; idx++) {
            int a, b;
            a = edges[idx].a, b = edges[idx].b;
            if(!st[a] && !st[b]) break;
        }
        if(idx == m) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}