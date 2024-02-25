#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

const int N = 10010;
int a, b, c;
int s1[N], s2[N], s3[N];

int getMin(int p1, int p2, int p3)
{
    int Min = INF, idx = -1;
    if(p1 != a - 1) {
        if(s1[p1] < Min) {
            Min = s1[p1];
            idx = 1;
        }
    }
    if(p2 != b - 1) {
        if(s2[p2] < Min) {
            Min = s2[p2];
            idx = 2;
        }
    }
    if(p3 != c - 1) {
        if(s3[p3] < Min) {
            Min = s3[p3];
            idx = 3;
        }
    }
    return idx;
}

int main()
{
    
    cin >> a >> b >> c;
    for(int i = 0; i < a; i++) cin >> s1[i];
    for(int i = 0; i < b; i++) cin >> s2[i];
    for(int i = 0; i < c; i++) cin >> s3[i];
    sort(s1, s1 + a);
    sort(s2, s2 + b);
    sort(s3, s3 + c);
    int p1 = 0, p2 = 0, p3 = 0;
    int resDist = INF, resP1, resP2, resP3;
    while(true) {
        int dist = abs(s1[p1] - s2[p2]) + abs(s2[p2] - s3[p3]) + abs(s3[p3] - s1[p1]);
        if(dist <= resDist) {
            resDist = dist;
            resP1 = p1;
            resP2 = p2;
            resP3 = p3;
        }
        int idx = getMin(p1, p2, p3);
        if(idx == 1) p1++;
        else if(idx == 2) p2++;
        else if(idx == 3) p3++;
        else break;
    }
    printf("MinD(%d, %d, %d) = %d\n", s1[resP1], s2[resP2], s3[resP3], resDist);
    return 0;
}