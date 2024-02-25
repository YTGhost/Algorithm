#include <iostream>
#include <cstring>
using namespace std;

int n, m;
const int N = 205;
int g[N][N];
int nodes[305];
int st[N];

bool checkEvery()
{
    for(int i = 1; i <= n; i++) {
        if(!st[i]) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i++) {
        int c1, c2, dist;
        cin >> c1 >> c2 >> dist;
        g[c1][c2] = g[c2][c1] = min(g[c1][c2], dist);
    }
    int k;
    cin >> k;
    int minDist = 0x3f3f3f3f, minNum;
    for(int i = 1; i <= k; i++) {
        int cnt;
        cin >> cnt;
        memset(st, 0, sizeof st);
        int dist = 0;
        for(int j = 0; j < cnt; j++) {
            cin >> nodes[j];
            st[nodes[j]] = 1;
        }
        for(int i = 0; i < cnt -1 ; i++) {
            if(g[nodes[i]][nodes[i+1]] == 0x3f3f3f3f) {
                dist = 0x3f3f3f3f;
                break;
            }
            dist += g[nodes[i]][nodes[i+1]];
        }
        bool isEvery = checkEvery();
        string str;
        if(nodes[0] == nodes[cnt-1] && dist != 0x3f3f3f3f) {
            if(isEvery) {
                if(cnt == n + 1) {
                    str = "TS simple cycle";
                    if(dist < minDist) {
                        minDist = dist;
                        minNum = i;
                    }
                } else {
                    str = "TS cycle";
                    if(dist < minDist) {
                        minDist = dist;
                        minNum = i;
                    }
                }
            } else {
                str = "Not a TS cycle";
            }
        } else {
            str = "Not a TS cycle";
        }
        if(dist == 0x3f3f3f3f) {
            printf("Path %d: NA (%s)\n", i, str.c_str());
        } else {
            printf("Path %d: %d (%s)\n", i, dist, str.c_str());
        }
    }
    printf("Shortest Dist(%d) = %d\n", minNum, minDist);
    return 0;
}