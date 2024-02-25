#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, M;
struct Node{
    int n, a;
    
    bool operator< (const Node& t) const {
        if(n != t.n) return n < t.n;
        return a < t.a;
    }
};
vector<Node> res;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int sumDigit(int x)
{
    int sum = 0;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i <= x / i; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(int depth, int m, int num)
{
    if(depth == K && m == M) {
        int n = sumDigit(num + 1);
        int g = gcd(m, n);
        if(g > 2 && isPrime(g)) {
            res.push_back({n, num});
        }
        return;
    }
    if(depth > K || m + 9 * (K - depth) < M) return;
    for(int i = 0; i <= 9; i++) dfs(depth + 1, m + i, num * 10 + i);
}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> K >> M;
        printf("Case %d\n", i);
        res.clear();
        dfs(0, 0, 0);
        sort(res.begin(), res.end());
        if(res.size()) {
            for(auto item : res) {
                printf("%d %d\n", item.n, item.a);
            }
        } else {
            printf("No Solution\n");
        }
    }
    return 0;
}