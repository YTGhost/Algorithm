#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 50010;
int n;
int preorder[N], inorder[N];
unordered_map<int, int> l, r, pos;
int res, flag;

int build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];
    
    if(k > il) l[root] = build(il, k-1, pl + 1, pl + 1 + k - 1 - il);
    if(k < ir) r[root] = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    return root;
}

void dfs(int u)
{
    if(!u) return;
    dfs(l[u]);
    dfs(r[u]);
    if(!flag) {
        cout << u << endl;
        flag = 1;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> preorder[i];
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    
    int root = build(0, n-1, 0, n-1);
    dfs(root);
    return 0;
}