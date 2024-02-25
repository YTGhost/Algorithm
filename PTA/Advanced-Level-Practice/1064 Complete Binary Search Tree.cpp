#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;

int w[N], nodes[N];
int n;

void dfs(int u, int &k)
{
    if(2 * u <= n) dfs(2 * u, k);
    nodes[u] = w[k++];
    if(2 * u + 1 <= n) dfs(2 * u + 1, k);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    
    int k = 0;
    dfs(1, k);
    
    cout << nodes[1];
    for(int i = 2; i <= n; i++) cout << " " << nodes[i];
    cout << endl;
    return 0;
}