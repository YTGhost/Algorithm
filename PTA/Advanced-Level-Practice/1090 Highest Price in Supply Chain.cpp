#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100010;
int n;
double P, R;
int p[N], f[N], leaf[N];
double maxPrice;
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
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == -1) root = i;
        else leaf[x] = 1;
        p[i] = x;
    }
    for(int i = 0; i < n; i++) {
        if(!leaf[i]) {
            double price = P * pow(1 + R / 100, dfs(i));
            if(price > maxPrice) {
                maxPrice = price;
                cnt = 1;
            } else if(price == maxPrice) {
                cnt++;
            }
        }
    }
    printf("%.2lf %d\n", maxPrice, cnt);
    return 0;
}