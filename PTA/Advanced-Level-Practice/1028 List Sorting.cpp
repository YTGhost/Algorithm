#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

struct Student 
{
    string id, name;
    int grade;
} students[N];

bool cmp1(Student a, Student b)
{
    return a.id < b.id;
}

bool cmp2(Student a, Student b)
{
    if(a.name == b.name) {
        return a.id < b.id;
    }
    return a.name < b.name;
}

bool cmp3(Student a, Student b)
{
    if(a.grade == b.grade) {
        return a.id < b.id;
    }
    return a.grade < b.grade;
}

int main()
{
    int n, c;
    cin >> n >> c;
    
    for(int i = 0; i < n; i++) {
        string id, name;
        int grade;
        cin >> id >> name >> grade;
        students[i] = {id, name, grade};
    }
    
    if(c == 1) {
        sort(students, students + n, cmp1);
    } else if(c == 2) {
        sort(students, students + n, cmp2);
    } else {
        sort(students, students + n, cmp3);
    }
    for(int i = 0; i < n; i++) {
        printf("%s %s %d\n", students[i].id.c_str(), students[i].name.c_str(), students[i].grade);
    }
    return 0;
}