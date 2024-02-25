#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;

vector<int> div(vector<int> &a, int b, int &r)
{
    vector<int> c;
    for(int i = a.size()-1; i >= 0; i--) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main()
{
    string str;
    int b;
    cin >> str >> b;
    for(int i = str.size()-1; i >= 0; i--) a.push_back(str[i] - '0');
    int r = 0;
    auto c = div(a, b, r);
    for(int i = c.size()-1; i >= 0; i--) printf("%d", c[i]);
    cout << endl;
    cout << r << endl;
    return 0;
}