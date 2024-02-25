#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;

int n, k;
const int N = 205;
string s, e = "ROM";
unordered_map<string, int> m;
int dist[N], g[N][N], sum[N], w[N], pre[N], cnt[N], pathNum[N];
bool st[N];
string citys[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    
    dist[0] = 0, pathNum[0] = 1;
    
    for(int i = 0; i < n-1; i++) {
        int t = -1;
        for(int j = 0; j < n; j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        
        for(int j = 0; j < n; j++) {
            if(dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                sum[j] = sum[t] + w[j];
                cnt[j] = cnt[t] + 1;
                pathNum[j] = pathNum[t];
                pre[j] = t;
            } else if(dist[j] == dist[t] + g[t][j]) {
                pathNum[j] += pathNum[t];
                if(sum[j] < sum[t] + w[j]) {
                    sum[j] = sum[t] + w[j];
                    cnt[j] = cnt[t] + 1;
                    pre[j] = t;
                } else if(sum[j] == sum[t] + w[j]) {
                    if(cnt[j] > cnt[t] + 1) {
                        cnt[j] = cnt[t] + 1;
                        pre[j] = t;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    cin >> s;
    m[s] = 0;
    citys[0] = s;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i < n; i++) {
        string city;
        int t;
        cin >> city >> t;
        m[city] = i;
        w[i] = t;
        citys[i] = city;
    }
    while(k--) {
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        g[m[c1]][m[c2]] = g[m[c2]][m[c1]] = min(g[m[c1]][m[c2]], cost);
    }
    
    dijkstra();
    
    int t = m[e];
    printf("%d %d %d %d\n", pathNum[t], dist[t], sum[t], sum[t] / cnt[t]);
    vector<int> path;
    for(int i = m[e]; i != 0; i = pre[i]) path.push_back(i);
    printf("%s->", citys[0].c_str());
    for(int i = path.size()-1; i >= 0; i--) {
        if(i) printf("%s->", citys[path[i]].c_str());
        else printf("%s", citys[path[i]].c_str());
    }
    return 0;
}