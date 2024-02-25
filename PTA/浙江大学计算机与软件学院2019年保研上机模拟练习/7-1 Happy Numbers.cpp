#include <iostream>
#include <unordered_set>
using namespace std;

int n;
unordered_set<int> s;

void isHappy(int x)
{
    s.clear();
    int p = x;
    bool flag = true;
    int cnt = 0;
    while(true) {
        if(p == 1) break;
        if(s.count(p)) {
            flag = false;
            break;
        } 
        s.insert(p);
        int sum = 0;
        while(p) {
            int t = p % 10;
            t *= t;
            sum += t;
            p /= 10;
        }
        cnt++;
        p = sum;
    }
    if(flag) printf("%d\n", cnt);
    else printf("%d\n", p);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        isHappy(x);
    }
    return 0;
}