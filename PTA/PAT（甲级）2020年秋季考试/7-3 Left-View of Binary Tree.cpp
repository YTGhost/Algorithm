#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

const int N = 25;
int n;
int inorder[N], preorder[N];
unordered_map<int, int> l, r, pos;
vector<int> res;

int build(int il, int ir, int pl, int pr)
{
    int root = preorder[pl];
    int k = pos[root];
    if(k > il) l[root] = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
    if(k < ir) r[root] = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);
    return root;
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int cnt = q.size();
        for(int i = 0; i < cnt; i++) {
            int t = q.front();
            q.pop();
            if(l[t]) q.push(l[t]);
            if(r[t]) q.push(r[t]);
            if(i == 0) res.push_back(t);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    for(int i = 0; i < n; i++) cin >> preorder[i];
    int root = build(0, n-1, 0, n-1);
    bfs(root);
    printf("%d", res[0]);
    for(int i = 1; i < res.size(); i++) printf(" %d", res[i]);
    cout << endl;
    return 0;
}