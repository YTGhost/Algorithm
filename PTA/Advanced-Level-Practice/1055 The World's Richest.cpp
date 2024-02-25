#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 210;
int n, k;

struct Person{
    string name;
    int age, w;
    
    bool operator< (const Person& t) const {
        if(w != t.w) return w > t.w;
        if(age != t.age) return age < t.age;
        return name < t.name;
    }
};

vector<Person> ages[N];
int idx[N];

int main()
{
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        string name;
        int age, w;
        cin >> name >> age >> w;
        ages[age].push_back({name, age, w});
    }
    
    for(int i = 1; i <= 200; i++) {
        sort(ages[i].begin(), ages[i].end());
    }
    
    for(int i = 1; i <= k; i++) {
        int m, aMin, aMax;
        cin >> m >> aMin >> aMax;
        printf("Case #%d:\n", i);
        memset(idx, 0, sizeof idx);
        bool flag = false;
        while(m--) {
            int t = -1;
            for(int j = aMin; j <= aMax; j++) {
                if(ages[j].size() > idx[j]) {
                    if(t == -1 || ages[j][idx[j]] < ages[t][idx[t]])
                    t = j;
                }
            }
            if(t == -1) break;
            auto p = ages[t][idx[t]];
            printf("%s %d %d\n", p.name.c_str(), p.age, p.w);
            idx[t]++;
            flag = true;
        }
        if(!flag) puts("None");
    }
    return 0;
}