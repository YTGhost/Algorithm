#include <iostream>
#include <cstring>
using namespace std;

const int N = 25;
int l[N], r[N];
int st[N];
int n;
int maxk, maxid;

void dfs(int u, int k)
{
    if(u == -1) return;
    
    if(k > maxk) {
        maxk = k;
        maxid = u;
    }
    
    dfs(l[u], 2 * k);
    dfs(r[u], 2 * k + 1);
    
}

int main()
{
    cin >> n;
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    for(int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if(a != "-") {
            l[i] = stoi(a);
            st[l[i]] = 1;
        }
        if(b != "-") {
            r[i] = stoi(b);
            st[r[i]] = 1;
        }
    }
    int root;
    for(int i = 0; i < n; i++) {
        if(st[i] == 0) {
            root = i;
            break;
        }
    }
    
    dfs(root, 1);
    
    if(maxk > n) cout << "NO" << " " << root << endl;
    else cout << "YES" << " " << maxid << endl;
    return 0;
}