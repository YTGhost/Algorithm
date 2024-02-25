#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Person {
  string id;
  int dx;
  int ch;
  int total;
  
  bool operator< (const Person& t) const {
      if(total != t.total) return total > t.total;
      if(dx != t.dx) return dx > t.dx;
      return id < t.id;
  }
};

int main()
{
    int n, l, h;
    vector<Person> sr;
    vector<Person> jz;
    vector<Person> yr;
    vector<Person> xr;
    cin >> n >> l >> h;
    for(int i = 0; i < n; i++) {
        string id;
        int dx, ch;
        cin >> id >> dx >> ch;
        if(dx >= l && ch >= l) {
            if(dx >= h && ch >= h) sr.push_back({id, dx, ch, dx + ch});
            else if(ch < h && dx >= h) jz.push_back({id, dx, ch, dx + ch});
            else if(ch < h && dx < h && dx >= ch) yr.push_back({id, dx, ch, dx + ch});
            else xr.push_back({id, dx, ch, dx + ch});
        }
    }
    sort(sr.begin(), sr.end());
    sort(jz.begin(), jz.end());
    sort(yr.begin(), yr.end());
    sort(xr.begin(), xr.end());
    cout << sr.size() + jz.size() + yr.size() + xr.size() << endl;
    for(auto item : sr) printf("%s %d %d\n", item.id.c_str(), item.dx, item.ch);
    for(auto item : jz) printf("%s %d %d\n", item.id.c_str(), item.dx, item.ch);
    for(auto item : yr) printf("%s %d %d\n", item.id.c_str(), item.dx, item.ch);
    for(auto item : xr) printf("%s %d %d\n", item.id.c_str(), item.dx, item.ch);
    return 0;
}