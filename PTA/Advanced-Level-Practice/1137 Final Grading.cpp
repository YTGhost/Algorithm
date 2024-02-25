#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Student
{
    string name;
    int p, m, f, s;
    
    Student(): p(-1), m(-1), f(-1), s(0) {}
    
    void calc() {
        if(f >= m) s = f;
        else s = round(m * 0.4 + f * 0.6);
    }
    
    bool operator< (const Student& t) const {
        if(s != t.s) return s > t.s;
        else return name < t.name;
    }
};

int p, m, n;
unordered_map<string, Student> map;

int main()
{
    string name;
    int grade;
    vector<Student> students;
    cin >> p >> m >> n;
    for(int i = 0; i < p; i++) {
        cin >> name >>grade;
        if(grade >= 200) {
            map[name].name = name;
            map[name].p = grade;
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> name >> grade;
        if(map.count(name)) {
            map[name].m = grade;
        }
    }
    for(int i = 0; i < n; i++) {
        cin >> name >> grade;
        if(map.count(name)) {
            map[name].f = grade;
        }
    }
    for(auto s : map) {
        s.second.calc();
        students.push_back(s.second);
    }
    sort(students.begin(), students.end());
    for(auto s : students) {
        if(s.s >= 60) {
            cout << s.name << " " << s.p << " " << s.m << " " << s.f << " " << s.s << endl;
        }
    }
    return 0;
}