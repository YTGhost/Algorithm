#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310;

struct Person
{
    int id, sum, a, b, c;
}q[N];

bool cmp(Person &a, Person &b)
{
    if(a.sum != b.sum) return a.sum > b.sum;
    if(a.a != b.a) return a.a > b.a;
    return a.id < b.id;
}

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
    
    sort(q + 1, q + n + 1, cmp);
    
    for(int i = 1; i <= 5; i++)
        cout << q[i].id << " " << q[i].sum << endl;
    return 0;
}