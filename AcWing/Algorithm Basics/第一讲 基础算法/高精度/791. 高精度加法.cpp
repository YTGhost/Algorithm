#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;

vector<int> add(vector<int> &a, vector<int> &b)
{
    int t = 0;
    vector<int> c;
    for(int i = 0; i < a.size() || i < b.size(); i++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if(t) c.push_back(1);
    return c;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    
    for(int i = str1.size()-1; i >= 0; i--) a.push_back(str1[i] - '0');
    for(int i = str2.size()-1; i >= 0; i--) b.push_back(str2[i] - '0');
    
    auto c = add(a, b);
    string res;
    for(int i = c.size()-1; i >= 0; i--) printf("%d", c[i]);
    return 0;
}