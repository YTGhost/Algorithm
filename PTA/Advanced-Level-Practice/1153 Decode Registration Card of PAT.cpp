#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 10010;

struct Student {
    string level;
    string locationId;
    string time;
    string id;
    int grade;
    string card;
    
    bool operator< (const Student &t) const {
        if(grade != t.grade) return grade > t.grade;
        return card < t.card;
    }
}students[N];

struct Location {
    string id;
    int cnt;
    
    bool operator< (const Location &t) const {
        if(cnt != t.cnt) return cnt > t.cnt;
        return id < t.id;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string id;
        int grade;
        cin >> id >> grade;
        students[i] = {id.substr(0, 1), id.substr(1, 3), id.substr(4, 6), id.substr(10, 3), grade, id};
    }
    for(int i = 1; i <= m; i++) {
        int type;
        string command;
        cin >> type >> command;
        printf("Case %d: %d %s\n", i, type, command.c_str());
        
        if(type == 1) {
            vector<Student> t;
            for(int j = 0; j < n; j++) {
                auto s = students[j];
                if(s.level == command) t.push_back(s);
            }
            if(t.size()) {
                sort(t.begin(), t.end());
                for(auto s : t) {
                    printf("%s %d\n", s.card.c_str(), s.grade);
                }
            } else {
                printf("NA\n");
            }
        } else if(type == 2) {
            int cnt = 0, totalGrade = 0;
            for(int j = 0; j < n; j++) {
                auto s = students[j];
                if(s.locationId == command) {
                    cnt++;
                    totalGrade += s.grade;
                }
            }
            if(cnt) {
                printf("%d %d\n", cnt, totalGrade);
            } else {
                printf("NA\n");
            }
        } else {
            unordered_map<string, int> map;
            vector<Location> locations;
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                auto s = students[j];
                if(s.time == command) {
                    map[s.locationId]++;
                    cnt++;
                }
            }
            if(cnt) {
                for(auto &[id, cnt] : map) {
                    locations.push_back({id, cnt});
                }
                sort(locations.begin(), locations.end());
                for(auto l : locations) {
                    printf("%s %d\n", l.id.c_str(), l.cnt);
                }
            } else {
                printf("NA\n");
            }
        }
    }
    return 0;
}