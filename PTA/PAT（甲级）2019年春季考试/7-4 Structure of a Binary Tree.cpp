#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 35;
int h[N];
unordered_map<int, int> pos, l, r, p, depth;
int poster[N], inorder[N];
int n, m;

int build(int il, int ir, int pl, int pr, int d)
{
    int root = poster[pr];
    depth[root] = d;
    int k = pos[root];
    if(k > il) {
        l[root] = build(il, k - 1, pl, pl + k - 1 - il, d + 1);
        p[l[root]] = root;
    }
    if(k < ir) {
        r[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1, d + 1);
        p[r[root]] = root;
    }
    return root;
}

bool dfs(int u, int idx)
{
    if(!u) return true;
    if(!l[u] && r[u] || l[u] && !r[u]) return false;
    return dfs(l[u], 2 * idx) && dfs(r[u], 2 * idx + 1);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> poster[i];
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    cin >> m;
    int root = build(0, n - 1, 0, n - 1, 0);
    getchar();
    while(m--) {
        string str;
        getline(cin, str);
        if(str.find("root") != -1) {
            int t;
            sscanf(str.c_str(), "%d is the root", &t);
            if(root == t) printf("Yes\n");
            else printf("No\n");
        } else if(str.find("siblings") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d and %d are siblings", &a, &b);
            if(p[a] == p[b]) printf("Yes\n");
            else printf("No\n");
        } else if(str.find("parent") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d is the parent of %d", &a, &b);
            if(p[b] == a) printf("Yes\n");
            else printf("No\n");
        } else if(str.find("left") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d is the left child of %d", &a, &b);
            if(l[b] == a) printf("Yes\n");
            else printf("No\n");
        } else if(str.find("right") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d is the right child of %d", &a, &b);
            if(r[b] == a) printf("Yes\n");
            else printf("No\n");
        } else if(str.find("same") != -1) {
            int a, b;
            sscanf(str.c_str(), "%d and %d are on the same level", &a, &b);
            if(depth[a] == depth[b]) printf("Yes\n");
            else printf("No\n");
        } else if(str.find("full") != -1) {
            if(dfs(root, 1)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}