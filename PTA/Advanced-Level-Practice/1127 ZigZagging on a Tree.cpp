#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

const int N = 35;
int inorder[N], postorder[N];
unordered_map<int, int> l, r, pos;
int n;

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];
    int k = pos[root];
    
    if(il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if(ir > k) r[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1);
    
    return root;
}

string bfs(int u, string &res)
{
    queue<int> q;
    q.push(u);
    int idx = 0;
    while(!q.empty()) {
        vector<int> nodes;
        while(!q.empty()) {
            nodes.push_back(q.front());
            q.pop();
        }
        for(auto node : nodes) {
            if(l.count(node)) q.push(l[node]);
            if(r.count(node)) q.push(r[node]);
        }
        if(idx % 2 == 0) {
            for(int i = nodes.size()-1; i >= 0; i--) {
                res += to_string(nodes[i]) + " ";
            }
        } else {
            for(int i = 0; i < nodes.size(); i++) {
                res += to_string(nodes[i]) + " ";
            }
        }
        idx++;
    }
    res.pop_back();
    return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }
    for(int i = 0; i < n; i++) cin >> postorder[i];
    
    int root = build(0, n-1, 0, n-1);
    string res;
    bfs(root, res);
    cout << res << endl;
    return 0;
}