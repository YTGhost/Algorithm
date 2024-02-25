#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 510;
int n, m, s, e;
int dist[N], g[N][N], cost[N], d[N][N], preG[N], preD[N], cnt[N];
bool st[N];

void dijkstraG()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 0; j < n; j++) {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        st[t] = true;
        for(int j = 0; j < n; j++) {
            if(dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                cost[j] = cost[t] + d[t][j];
                preG[j] = t;
            } else if(dist[j] == dist[t] + g[t][j]) {
                if(cost[j] > cost[t] + d[t][j]) {
                    cost[j] = cost[t] + d[t][j];
                    preG[j] = t;
                }
            }
        }
    }
}

void dijkstraD()
{
    memset(cost, 0x3f, sizeof cost);
    cost[s] = 0, cnt[s] = 1;
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 0; j < n; j++) {
            if(!st[j] && (t == -1 || cost[t] > cost[j]))
                t = j;
        }
        st[t] = true;
        for(int j = 0; j < n; j++) {
            if(cost[j] > cost[t] + d[t][j]) {
                cost[j] = cost[t] + d[t][j];
                cnt[j] = cnt[t] + 1;
                preD[j] = t;
            } else if(cost[j] == cost[t] + d[t][j]) {
                if(cnt[j] > cnt[t] + 1) {
                    cnt[j] = cnt[t] + 1;
                    preD[j] = t;
                }
            }
        }
    }
}

bool check(vector<int> &path1, vector<int> &path2)
{
    if(path1.size() != path2.size()) return false;
    for(int i = 0; i < path1.size(); i++) {
        if(path1[i] != path2[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(d, 0x3f, sizeof d);
    while(m--) {
        int v1, v2, oneWay, length, time;
        cin >> v1 >> v2 >> oneWay >> length >> time;
        if(oneWay == 1) {
            g[v1][v2] = min(g[v1][v2], length);
            d[v1][v2] = min(d[v1][v2], time);
        } else {
            g[v1][v2] = g[v2][v1] = min(g[v1][v2], length);
            d[v1][v2] = d[v2][v1] = min(d[v1][v2], time);
        }
    }
    cin >> s >> e;
    
    dijkstraG();
    for(int i = 0; i < N; i++) st[i] = false;
    dijkstraD();
    
    vector<int> path1;
    vector<int> path2;

    for(int i = e; i != s; i = preG[i]) path1.push_back(i);
    for(int i = e; i != s; i = preD[i]) path2.push_back(i);
    bool t = check(path1, path2);
    
    if(t) {
        printf("Distance = %d; Time = %d: %d", dist[e], cost[e], s);
        for(int i = path1.size()-1; i >= 0; i--) {
            printf(" -> %d", path1[i]);
        }
    } else {
        printf("Distance = %d: %d", dist[e], s);
        for(int i = path1.size()-1; i >= 0; i--) {
            printf(" -> %d", path1[i]);
        }
        printf("\n");
        printf("Time = %d: %d", cost[e], s);
        for(int i = path2.size()-1; i >= 0; i--) {
            printf(" -> %d", path2[i]);
        }
    }
    return 0;
}