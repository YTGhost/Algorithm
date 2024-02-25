#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 105, M = 10010;
int n, m;
int h[N], e[M], ne[M], idx;
int maxNum = 1, maxLevel = 1;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    queue<int> q;
    q.push(1);
    int level = 1;
    while(!q.empty()) {
        vector<int> nodes;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            nodes.push_back(t);
        }
        if(nodes.size() > maxNum) {
            maxNum = nodes.size();
            maxLevel = level;
        }
        for(auto node : nodes) {
            for(int i = h[node]; ~i; i = ne[i]) {
                q.push(e[i]);
            }
        }
        level++;
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++) {
        int id, k;
        cin >> id >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            add(id, x);
        }
    }
    bfs();
    cout << maxNum << " " << maxLevel << endl;
    return 0;
}