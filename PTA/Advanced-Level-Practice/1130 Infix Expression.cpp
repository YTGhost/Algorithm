#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 25;
int n;
unordered_map<int, int>l, r;
string w[N];
int st[N];
int root;

string dfs(int u)
{
    if(u == -1) return "";
    string left, right;
    if(l[u] != -1) left = dfs(l[u]);
    if(r[u] != -1) right = dfs(r[u]);
    
    if(u != root && (l[u] != -1 || r[u] != -1)) return "(" + left + w[u] + right + ")";
    else return left + w[u] + right;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string data;
        int left, right;
        cin >> data >> left >> right;
        l[i] = left, r[i] = right;
        w[i] = data;
        st[left] = 1, st[right] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        if(!st[i]) {
            root = i;
            break;
        }
    }
    string res = dfs(root);
    cout << res << endl;
    return 0;
}