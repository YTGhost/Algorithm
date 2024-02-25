#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N = 10010, M = 1000010;
int h[N], e[M], ne[M], w[M], line[M], idx;
int stops[N];
int st[N];
string info[N];
int dist[N], cnt[N], pre[N];
int n;
typedef pair<int, int> PII;

void add(int a, int b, int c, int id)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, line[idx] = id, h[a] = idx++;
}

string get_number(int x)
{
    char res[5];
    sprintf(res, "%04d", x);
    return res;
}

void dijkstra(int start, int end)
{
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0x3f, sizeof cnt);
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    dist[start] = cnt[start] = 0;
    
    while(q.size()) {
        auto item = q.top();
        q.pop();
        
        if (item.second == end) break;
        if(st[item.second]) continue;
        st[item.second] = 1;
        
        for(int i = h[item.second]; ~i; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[item.second] + w[i]) {
                dist[j] = dist[item.second] + w[i];
                cnt[j] = cnt[item.second] + 1;
                pre[j] = item.second;
                info[j] = "Take Line#" + to_string(line[i]) + " from " +
                    get_number(item.second) + " to " + get_number(j) + ".";
                q.push({dist[j], j});
            } else if(dist[j] == dist[item.second] + w[i]) {
                if(cnt[j] > cnt[item.second] + 1) {
                    cnt[j] = cnt[item.second] + 1;
                    pre[j] = item.second;
                    info[j] = "Take Line#" + to_string(line[i]) + " from " +
                        get_number(item.second) + " to " + get_number(j) + ".";
                }
            }
        }
    }
    cout << dist[end] << endl;
    vector<string> paths;
    for(int i = end; i != start; i = pre[i]) {
        paths.push_back(info[i]);
    }
    for(int i = paths.size()-1; i >= 0; i--) {
        cout << paths[i] << endl;
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        
        for(int j = 0; j < m; j++) cin >> stops[j];
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < j; k++) {
                int len;
                if(stops[0] != stops[m-1]) len = j - k;
                else len = min(j - k, m - 1 - j + k);
                add(stops[j], stops[k], len, i);
                add(stops[k], stops[j], len, i);
            }
        }
    }
    
    int k;
    cin >> k;
    while(k--) {
        int start, end;
        cin >> start >> end;
        dijkstra(start, end);
    }
    return 0;
}