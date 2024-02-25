#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310;

struct Person
{
    int id, sum, a, b, c;
    bool operator< (const Person& t) const
    {
        if(sum != t.sum) return sum > t.sum;
        if(a != t.a) return a > t.a;
        return id < t.id;
    }
}q[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        q[i] = {i, a+b+c, a, b, c};
    }
    
    sort(q + 1, q + n + 1);
    
    for(int i = 1; i <= 5; i++)
        cout << q[i].id << " " << q[i].sum << endl;
    return 0;
}