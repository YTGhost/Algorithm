#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

const int K = 6;
int p[K];
int n, k, m;

struct Student
{
    int userId, totalScore, cnt, rank, validCnt;
    int score[K];
    
    Student(){}
    Student(int _userId) : userId(_userId) {
        totalScore = 0, cnt = 0, rank = 0, validCnt = 0;
        for(int i = 0; i < K; i++) {
            score[i] = -2;
        }
    }
    
    void calc() {
        for(int i = 1; i <= k; i++) {
            totalScore += score[i] == -2 || score[i] == -1 ? 0 : score[i];
            if(score[i] == p[i]) cnt++;
            if(score[i] >= 0) validCnt++;
        }
    }
    
    bool operator< (const Student& t) const {
        if(totalScore != t.totalScore) {
            return totalScore > t.totalScore;
        } else {
            if(cnt != t.cnt) {
                return cnt > t.cnt;
            } else {
                return userId < t.userId;
            }
        }
    }
};


int main()
{
    unordered_map<int, Student> map;
    vector<Student> students;
    cin >> n >> k >> m;
    
    for(int i = 1; i <= k; i++) {
        int grade;
        cin >> grade;
        p[i] = grade;
    }
    
    for(int i = 0; i < m; i++) {
        int userId, problemId, score;
        cin >> userId >> problemId >> score;
        if(!map.count(userId)) {
            map[userId] = Student(userId);
        }
        map[userId].score[problemId] = max(map[userId].score[problemId], score);
    }
    
    for(auto s : map) {
        s.second.calc();
        students.push_back(s.second);
    }
    
    sort(students.begin(), students.end());
    int rank = 1;
    int pre = -1;
    for(int i = 0; i < students.size(); i++) {
        if(students[i].validCnt) {
            students[i].rank = students[i].totalScore != pre ? rank : students[i-1].rank;
            printf("%d %05d %d", students[i].rank, students[i].userId, students[i].totalScore);
            for(int j = 1; j <= k; j++) {
                printf(" ");
                if(students[i].score[j] == -2) {
                    printf("-");
                } else {
                    printf("%d", students[i].score[j] == -1 ? 0 : students[i].score[j]);
                }
            }
            cout << endl;
            rank++;
            pre = students[i].totalScore;
        }
    }
    return 0;
}