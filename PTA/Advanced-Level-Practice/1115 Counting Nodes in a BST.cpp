#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int n;
int l[N], r[N], w[N], idx;
int cnt[N], max_depth;

void insert(int &u, int x)
{
    if(!u) {
        u = ++idx;
        w[u] = x;
    } else if(x <= w[u]) insert(l[u], x);
    else insert(r[u], x);
}

void dfs(int u, int depth)
{
    if(!u) return;
    cnt[depth]++;
    max_depth = max(max_depth, depth);
    dfs(l[u], depth + 1);
    dfs(r[u], depth + 1);
}

int main()
{
    cin >> n;
    
    int root = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }
    
    dfs(root, 0);
    printf("%d + %d = %d", cnt[max_depth], cnt[max_depth-1], cnt[max_depth] + cnt[max_depth-1]);
    return 0;
}