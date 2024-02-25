#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
  string str;
  int cnt;
  
  bool operator< (const Item& t) const {
      if(cnt != t.cnt) return cnt > t.cnt;
      return str < t.str;
  }
};

int main()
{
    string str;
    getline(cin, str);
    unordered_map<string, int> map;
    vector<Item> items;
    int sign = 0;
    string t = "";
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            char temp = str[i];
            if(temp >= 'A' && temp <= 'Z') {
                temp = 'a' + temp - 'A';
            }
            t += temp;
        } else {
            if(t == "") continue;
            else {
                map[t]++;
                t = "";
            }
        }
    }
    if(t != "") map[t]++;
    for(auto &[str, cnt] : map) {
        items.push_back({str, cnt});
    }
    sort(items.begin(), items.end());
    printf("%s %d", items[0].str.c_str(), items[0].cnt);
    return 0;
}