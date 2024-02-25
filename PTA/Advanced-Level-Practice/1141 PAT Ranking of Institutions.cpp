#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

struct Student {
  string id;
  double grade;
  string school;
};

struct School {
    string name;
    double bGrade;
    double aGrade;
    double tGrade;
    double totalGrade;
    int cnt;
    
    void calc() {
        totalGrade = floor(bGrade / 1.5 + aGrade + tGrade * 1.5);
    }
    
    bool operator< (const School& t) const {
        if(totalGrade != t.totalGrade) return totalGrade > t.totalGrade;
        if(cnt != t.cnt) return cnt < t.cnt;
        return name < t.name;
    }
};

int main()
{
    int n;
    vector<Student> students;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string id, school;
        double grade;
        cin >> id >> grade >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        students.push_back({id, grade, school});
    }
    unordered_map<string, School> map;
    vector<School> schools;
    for(auto student : students) {
        if(student.id[0] == 'B') {
            map[student.school].bGrade += student.grade;
        } else if(student.id[0] == 'A') {
            map[student.school].aGrade += student.grade;
        } else {
            map[student.school].tGrade += student.grade;
        }
        map[student.school].name = student.school;
        map[student.school].cnt++;
    }
    for(auto &[_, school] : map) {
        school.calc();
        schools.push_back(school);
    }
    sort(schools.begin(), schools.end());
    int rank = 1;
    cout << schools.size() << endl;
    for(int i = 0; i < schools.size(); i++) {
        auto s = schools[i];
        if(i && s.totalGrade != schools[i-1].totalGrade) rank = i + 1;
        printf("%d %s %d %d\n", rank, s.name.c_str(), (int)s.totalGrade, s.cnt);
    }
    return 0;
}