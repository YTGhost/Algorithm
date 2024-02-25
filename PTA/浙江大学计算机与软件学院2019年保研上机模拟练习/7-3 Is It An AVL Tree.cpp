#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 35;
int k, n;
unordered_map<int, int> pos, l, r, h;
int preorder[N], inorder[N];

int get_balance(int u)
{
    return h[l[u]] - h[r[u]];
}

int build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];
    if(k > il) l[root] = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
    if(k < ir) r[root] = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    h[root] = max(h[l[root]], h[r[root]]) + 1;
    return root;
}

bool dfs(int u)
{
    if(!u) return true;
    if(!l[u] && !r[u]) return true;
    int balance = get_balance(u);
    bool flag1 = balance == 1 || balance == -1 || balance == 0;
    bool flag2 = true;
    bool flag3 = true;
    if(l.count(u)) flag2 = dfs(l[u]);
    if(r.count(u)) flag3 = dfs(r[u]);
    return flag1 && flag2 && flag3;
}

int main()
{
    cin >> k;
    while(k--) {
        pos.clear();
        h.clear();
        l.clear();
        r.clear();
        memset(preorder, 0, sizeof preorder);
        memset(inorder, 0, sizeof inorder);
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> preorder[i];
            inorder[i] = preorder[i];
        }
        sort(inorder, inorder + n);
        for(int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        int root = build(0, n - 1, 0, n - 1);
        bool flag = dfs(root);
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}