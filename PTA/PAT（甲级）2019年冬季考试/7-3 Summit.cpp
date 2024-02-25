#include <iostream>
#include <map>
#include <cstring>
using namespace std;

const int N = 205;
int g[N][N];
int n, m, k;
int st[N];
int area[N];

int main()
{
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    cin >> k;
    for(int i = 1; i <= k; i++) {
        memset(st, 0, sizeof st);
        int l;
        cin >> l;
        for(int j = 0; j < l; j++) {
            cin >> area[j];
            st[area[i]] = 1;
        }
        bool flag = true;
        for(int j = 0; j < l - 1; j++) {
            for(int r = j + 1; r < l; r++) {
                if(!g[area[j]][area[r]]) {
                    flag = false;
                    break;
                }
                if(!flag) break;
            }
        }
        if(!flag) {
            printf("Area %d needs help.\n", i);
        } else {
            int ans = -1;
            for(int j = 1; j <= n; j++) {
                if(st[j]) continue;
                bool exist = true;
                for(int r = 0; r < l; r++) {
                    if(!g[j][area[r]]) {
                        exist = false;
                        break;
                    }
                }
                if(exist) {
                    ans = j;
                    break;
                }
            }
            if(ans == -1) {
                printf("Area %d is OK.\n", i);
            } else {
                printf("Area %d may invite more people, such as %d.\n", i, ans);
            }
        }
    }
    return 0;
}