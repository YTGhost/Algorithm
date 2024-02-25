#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1010, M = N * N;
int g[N][N];
int k, n, m;
int caller[N];
vector<int> callers;
vector<int> suspects;
int p[N];
int idx = 1;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> k >> n >> m;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] += c;
        caller[a] = 1;
    }
    for(int i = 1; i <= n; i++) {
        if(caller[i]) callers.push_back(i);
    }
    for(auto caller : callers) {
        int callCnt = 0, callBackCnt = 0;
        for(int i = 1; i <= n; i++) {
            if(g[caller][i] > 0 && g[caller][i] <= 5) {
                callCnt++;
                if(g[i][caller]) callBackCnt++;
            }
        }
        if(callCnt > k && callBackCnt * 5 <= callCnt) suspects.push_back(caller);
    }
    if(suspects.size()) {
        for(auto suspect : suspects) p[suspect] = suspect;
        for(int i = 0; i < suspects.size() - 1; i++) {
            for(int j = i + 1; j < suspects.size(); j++) {
                int a = suspects[i], b = suspects[j];
                if(g[a][b] && g[b][a]) p[find(b)] = find(a);
            }
        }
        unordered_map<int, vector<int>> mp;
        for(auto suspect : suspects) mp[find(suspect)].push_back(suspect);
        vector<vector<int>> res;
        for(auto item : mp) res.push_back(item.second);
        sort(res.begin(), res.end());
        for(auto item : res) {
            printf("%d", item[0]);
            for(int i = 1; i < item.size(); i++) printf(" %d", item[i]);
            printf("\n");
        }
    } else {
        printf("None\n");
    }
    return 0;
}