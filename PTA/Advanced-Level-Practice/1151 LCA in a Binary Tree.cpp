#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 10010;
int m, n;
int inorder[N], preorder[N], seq[N];
unordered_map<int, int> pos;
int p[N], depth[N];

int build(int il, int ir, int pl, int pr, int d)
{
    int root = preorder[pl];
    int k = root;
    
    depth[root] = d;
    if(il < k) p[build(il, k - 1, pl + 1, pl + 1 + k - 1 - il, d + 1)] = root;
    if(k < ir) p[build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr, d + 1)] = root;
    return root;
}

int main()
{
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
        pos[seq[i]] = i;
        inorder[i] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> preorder[i];
        preorder[i] = pos[preorder[i]];
    }
    build(0, n - 1, 0, n - 1, 0);
    while(m--) {
        int u, v;
        cin >> u >> v;
        if(pos.count(u) && pos.count(v)) {
            u = pos[u], v = pos[v];
            int a = u, b = v;
            while(u != v) {
                if(depth[u] < depth[v]) v = p[v];
                else u = p[u];
            }
            if(a != u && b != u) {
                printf("LCA of %d and %d is %d.\n", seq[a], seq[b], seq[u]);
            } else if(a == u) {
                printf("%d is an ancestor of %d.\n", seq[a], seq[b]);
            } else {
                printf("%d is an ancestor of %d.\n", seq[b], seq[a]);
            }
        } else if(pos.count(u) == 0 && pos.count(v) == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if(pos.count(u)) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            printf("ERROR: %d is not found.\n", u);
        }
    }
    return 0;
}