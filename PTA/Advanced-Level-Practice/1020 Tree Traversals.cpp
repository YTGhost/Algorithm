#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

const int N = 35;
int inorder[N], postorder[N];
unordered_map<int, int> l, r, pos;

int build(int pl, int pr, int il, int ir)
{
    int root = postorder[pr];
    int inorderRoot = pos[root];
    if(inorderRoot > il) l[root] = build(pl, inorderRoot - 1 - il + pl, il, inorderRoot - 1);
    if(inorderRoot < ir) r[root] = build(inorderRoot - il + pl, pr - 1, inorderRoot + 1, ir);
    return root;
}

void bfs(int x)
{
    queue<int> q;
    int sign = false;
    q.push(x);
    while(!q.empty()) {
        int root = q.front();
        if(sign) cout << " " << root;
        else {
            cout << root;
            sign = true;
        };
        q.pop();
        if(l.count(root)) q.push(l[root]);
        if(r.count(root)) q.push(r[root]);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> postorder[i];
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n-1, 0, n-1);
    bfs(root);
    return 0;
}