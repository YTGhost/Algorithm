#include <iostream>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100010;
int n, m;
int nums[N];
int t;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> nums[i];
    priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int, vector<int>, greater<int>> bq;
    for(int i = 0; i < m; i++) q.push(nums[i]);
    t = q.top();
    q.pop();
    printf("%d", t);
    for(int i = m; i < n; i++) {
        int num = nums[i];
        if(num < t) {
            q.push(INF);
            bq.push(num);
        } else {
            q.push(num);
        }
        if(q.top() == INF) {
            while(!q.empty()) q.pop();
            printf("\n");
            int first = bq.top();
            bq.pop();
            t = first;
            printf("%d", first);
            while(bq.size()) {
                int item = bq.top();
                bq.pop();
                q.push(item);
            }
            continue;
        }
        int item = q.top();
        q.pop();
        t = item;
        printf(" %d", item);
    }
    if(q.size()) {
        while(q.size()) {
            int item = q.top();
            if(item == INF) break;
            q.pop();
            printf(" %d", item);
        }
    }
    if(bq.size()) {
        printf("\n");
        bool isFirst = true;
        while(bq.size()) {
            int item = bq.top();
            bq.pop();
            if(isFirst) printf("%d", item), isFirst = false;
            else printf(" %d", item);
        }
    }
    return 0;
}