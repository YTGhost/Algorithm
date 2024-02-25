#include <iostream>
#include <vector>
using namespace std;

vector<int> a, b;

bool cmp(vector<int> &a, vector<int>& b)
{
    if(a.size() != b.size()) {
        return a.size() > b.size();
    } else {
        for(int i = a.size()-1; i >= 0; i--) {
            if(a[i] != b[i]) return a[i] > b[i];
        }
    }
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
    int t = 0;
    vector<int> c;
    for(int i = 0; i < a.size(); i++) {
        t = a[i] - t;
        if(i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    for(int i = str1.size()-1; i >= 0; i--) a.push_back(str1[i] - '0');
    for(int i = str2.size()-1; i >= 0; i--) b.push_back(str2[i] - '0');

    string res;
    if(cmp(a, b)) {
        auto c = sub(a, b);
        for(int i = c.size()-1; i >= 0; i--) printf("%d", c[i]);
    } else {
        auto c = sub(b, a);
        printf("-");
        for(int i = c.size()-1; i >= 0; i--) printf("%d", c[i]);
    }
    return 0;
}