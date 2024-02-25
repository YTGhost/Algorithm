#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = N * N;
int n, r, k;
int h[N], e[M], ne[M], idx;
int region[N];
int st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> r >> k;
    for(int i = 1; i <= r; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int m;
    cin >> m;
    while(m--) {
        int cnt = 0;
        memset(st, 0, sizeof st);
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            region[i] = x;
            if(!st[x]) {
                st[x] = 1;
                cnt++;
            }
        }
        if(cnt > k) printf("Error: Too many species.\n");
        else if(cnt < k) printf("Error: Too few species.\n");
        else {
            bool isValid = true;
            for(int j = 1; j <= n; j++) {
                for(int t = h[j]; ~t; t = ne[t]) {
                    int val = e[t];
                    if(region[j] == region[val]) {
                        isValid = false;
                        break;
                    }
                }
                if(!isValid) break;
            }
            if(isValid) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}