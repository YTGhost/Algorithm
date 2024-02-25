#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 100010;
int items[N], coupons[N];
int n, d;
int cnt;

struct Node{
    int price, coupon;
    
    bool operator< (const Node& t) const {
        return price - coupons[coupon] > t.price - coupons[t.coupon];
    }
};

int main()
{
    cin >> n >> d;
    for(int i = 0; i < n; i++) cin >> items[i];
    for(int i = 0; i < n; i++) cin >> coupons[i];
    sort(items, items + n);
    sort(coupons, coupons + n);
    bool flag = false;
    priority_queue<Node> q;
    for(int i = 0; i < n; i++) {
        q.push({items[i], n-1});
    }
    while(q.size()) {
        auto item = q.top();
        q.pop();
        int pay = item.price - coupons[item.coupon];
        if(d >= pay) {
            d -= pay;
            cnt++;
            if(item.coupon != 0) q.push({item.price, item.coupon - 1});
        }
        else {
            break;
        }
    }
    printf("%d %d\n", cnt, d);
    return 0;
}