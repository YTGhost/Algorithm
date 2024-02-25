#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 110, M = 10010;
vector<vector<int>> res;
int h[N], e[M], ne[M], idx, w[N];
int n, m, s;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int root, vector<int> path, long long sum)
{
    if(h[root] == -1 && sum == s) {
        res.push_back(path);
        return;
    }
    
    for(int i = h[root]; ~i; i = ne[i]) {
        int node = e[i];
        path.push_back(w[node]);
        dfs(node, path, sum + w[node]);
        path.pop_back();
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++) cin >> w[i];
    
    for(int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            add(id, x);
        }
    }
    vector<int> path({w[0]});
    dfs(0, path, w[0]);
    sort(res.begin(), res.end(), greater<vector<int>>());
    for(auto item : res) {
        cout << item[0];
        for(int i = 1; i < item.size(); i++) cout << " " << item[i];
        cout << endl;
    }
    return 0;
}