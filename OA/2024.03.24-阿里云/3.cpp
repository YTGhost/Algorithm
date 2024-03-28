// 贪心
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    queue<int> q;
    q.push(0);
    long long res = cost[0];
    for(int i = 1; i < n - 1; i++) {
        while(q.size() && cost[q.front()] + i - q.front() >= cost[i]) {
            q.pop();
        }
        q.push(i);
        res += cost[q.front()] + i - q.front();
    }
    cout << res << endl;
    return 0;
}