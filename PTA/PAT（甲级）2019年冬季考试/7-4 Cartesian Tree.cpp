#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

const int N = 45, INF = 0x3f3f3f3f;
int n;
unordered_map<int, int> lm, rm;
int inorder[N];
unordered_map<int, int> pos;
vector<int> res;

int findMin(int l, int r)
{
    int root = INF; 
    for(int i = l; i <= r; i++) {
        root = min(root, inorder[i]);
    }
    return root;
}

int build(int l, int r)
{
    int root = findMin(l, r);
    int k = pos[root];
    if(k > l) lm[root] = build(l, k - 1);
    if(k < r) rm[root] = build(k + 1, r);
    return root;
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while(q.size()) {
        int item = q.front();
        q.pop();
        res.push_back(item);
        if(lm.count(item)) q.push(lm[item]);
        if(rm.count(item)) q.push(rm[item]);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    int root = build(0, n - 1);
    bfs(root);
    for(int i = 0; i < res.size(); i++) {
        if(i == 0) printf("%d", res[i]);
        else printf(" %d", res[i]);
    }
    cout << endl;
    return 0;
}