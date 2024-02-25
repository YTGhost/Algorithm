#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1010;
vector<int> hobby[N];
int p[N];
int cnt[N];

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d:", &k);
        while(k--)
        {
            int h;
            cin >> h;
            hobby[h].push_back(i);
        }
    }
    
    for(int i = 1; i <= n; i++) p[i] = i;
    
    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 0; j < hobby[i].size(); j++)
        {
            int a = hobby[i][0], b = hobby[i][j];
            p[find(a)] = find(b);
        }
    }
    
    for(int i = 1; i <= n; i++) cnt[find(i)]++;
    sort(cnt, cnt + n + 1, greater<int>());
    int k = 0;
    while(cnt[k]) k++;
    cout << k << endl;
    cout << cnt[0];
    for(int i = 1; i < k; i++) cout << " " << cnt[i];
    cout << endl;
    return 0;
}