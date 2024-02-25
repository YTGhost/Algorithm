#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

const int N = 1010;
int n, m;
int h[N];
unordered_map<int, int> p, l, r;

void up(int x)
{
    while(x / 2 && h[x] > h[x / 2]) {
        swap(h[x], h[x / 2]);
        x /= 2;
    }
}

int dfs(int u)
{
    if(2 * u <= n) l[h[u]] = dfs(2 * u), p[h[2 * u]] = h[u];
    if(2 * u + 1 <= n) r[h[u]] = dfs(2 * u + 1), p[h[2 * u + 1]] = h[u];
    return h[u];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        up(i);
    }
    dfs(1);
    getchar();
    while(m--) {
        string str;
        getline(cin, str);
        bool flag = true;
        if(str.find("root") != -1) {
            int x;
            sscanf(str.c_str(), "%d is the root", &x);
            flag = x == h[1];
        } else if(str.find("siblings") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d and %d are siblings", &a, &b);
            if(!p.count(a) || !p.count(b)) flag = false;
            else flag = p[a] == p[b];
        } else if(str.find("parent") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d is the parent of %d", &a, &b);
            if(!p.count(b)) flag = false;
            else flag = p[b] == a;
        } else if(str.find("left") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d is the left child of %d", &a, &b);
            if(!p.count(a)) flag = false;
            else flag = l[b] == a;
        } else if(str.find("right") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d is the right child of %d", &a, &b);
            if(!p.count(a)) flag = false;
            else flag = r[b] == a;
        }
        if(flag) printf("1");
        else printf("0");
    }
    return 0;
}