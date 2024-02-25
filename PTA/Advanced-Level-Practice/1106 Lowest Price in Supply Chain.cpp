#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100010;
int n;
double P, R;
int p[N], f[N], leaf[N];
double minPrice = 0x3f3f3f3f;
int cnt;
int root;

int dfs(int u)
{
    if(f[u] != -1) return f[u];
    else if(p[u] == -1) return 0;
    else return f[u] = dfs(p[u]) + 1;
}

int main()
{
    cin >> n >> P >> R;
    memset(f, -1, sizeof f);
    memset(p, -1, sizeof p);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int id;
            cin >> id;
            p[id] = i;
        }
        if(k == 0) {
            leaf[i] = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        if(leaf[i]) {
            double price = P * pow(1 + R / 100, dfs(i));
            if(price < minPrice) {
                minPrice = price;
                cnt = 1;
            } else if(price == minPrice) {
                cnt++;
            }
        }
    }
    printf("%.4lf %d\n", minPrice, cnt);
    return 0;
}