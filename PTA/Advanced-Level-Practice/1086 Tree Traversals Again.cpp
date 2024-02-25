#include <iostream>
#include <stack>
using namespace std;

const int N = 35;
int l[N], r[N];

void dfs(int u, int root)
{
    if(!u) return;
    
    dfs(l[u], root);
    dfs(r[u], root);
    
    if(u == root) cout << u << endl;
    else cout << u << " ";
}

int main()
{
    int n;
    cin >> n;
    
    int last = 0, type = -1, root;
    stack<int> stk;
    for(int i = 0; i < 2 * n; i++) {
        string op;
        cin >> op;
        if(op == "Push") {
            int x;
            cin >> x;
            if(type == -1) root = x;
            else {
                if(type == 1) l[last] = x;
                else r[last] = x;
            }
            type = 1;
            last = x;
            stk.push(x);
        } else {
            int x = stk.top();
            stk.pop();
            type = 0;
            last = x;
        }
    }
    
    dfs(root, root);
    return 0;
}