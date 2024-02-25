#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
int n;
int h[N];
int isMax, isMin;

void dfs(int u, vector<int> path)
{
    path.push_back(h[u]);
    if(2 * u + 1 > n && 2 * u > n) {
        cout << path[0];
        for(int i = 1; i < path.size(); i++) {
            cout << " " << path[i];
        }
        cout << endl;
        return;
    }
    if(2 * u + 1 <= n) {
        if(h[u] >= h[2 * u + 1]) isMax++;
        else isMin++;
        dfs(2 * u + 1, path);
    }
    if(2 * u <= n) {
        if(h[u] >= h[2 * u]) isMax++;
        else isMin++;
        dfs(2 * u, path);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<int> path;
    dfs(1, path);
    if(isMax && isMin) cout << "Not Heap" << endl;
    else if(isMax) cout << "Max Heap" << endl;
    else cout << "Min Heap" << endl;
    return 0;
}