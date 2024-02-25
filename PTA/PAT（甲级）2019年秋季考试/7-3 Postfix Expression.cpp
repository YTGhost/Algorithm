#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 25;
int n;
unordered_map<int, int> l, r;
string data[N];
int st[N];

void dfs(int u)
{
    if(u == -1) return;
    printf("(");
    if(l[u] == -1 || r[u] == -1) printf("%s", data[u].c_str());
    dfs(l[u]);
    dfs(r[u]);
    if(l[u] != -1 && r[u] != -1) printf("%s", data[u].c_str());
    printf(")");
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int left, right;
        cin >> data[i] >> left >> right;
        l[i] = left, st[left] = 1;
        r[i] = right, st[right] = 1;
    }
    int root;
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            root = i;
            break;
        }
    }
    dfs(root);
    cout << endl;
    return 0;
}