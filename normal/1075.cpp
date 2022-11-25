#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Student {
    int id;
    vector<int> scoreList;
    int totalScore;
    Student(int scoreCount) { scoreList = vector<int>(scoreCount, -2); }
    bool isQualified = false;
};
bool cmp(const Student& s1, const Student& s2) {
    if (s1.totalScore != s2.totalScore) {
        return s1.totalScore > s2.totalScore;
    } else {
        return s1.id > s2.id;
    }
}
int main() {
    int studentCount, problemCount, submitionCount;
    cin >> studentCount >> problemCount >> submitionCount;
    vector<int> markList(problemCount);
    for (auto& i : markList) {
        cin >> i;
    }
    vector<Student> studentList(studentCount, Student(problemCount));
    for (int i = 1; i <= studentCount; ++i) {
        studentList[i - 1].id = i;
    }
    for (int i = 0; i < submitionCount; ++i) {
        int id, pId, score;
        cin >> id >> pId >> score;
        studentList[id - 1].scoreList[pId] =
            max(studentList[id - 1].scoreList[pId], score);
    }
    for (int i = 0; i < studentCount; ++i) {
        int temp = 0;
        for (int j = 0; j < problemCount; ++j) {
            if (studentList[i].scoreList[j] > 0) {
                temp += studentList[i].scoreList[j];
                studentList[i].isQualified = true;
            }
        }
        studentList[i].totalScore = temp;
    }
    sort(studentList.begin(), studentList.end(), cmp);
    for (auto i : studentList) {
        if (i.isQualified) {
            printf("%05d %d ", i.id, i.totalScore);
            for (int j = 0; j < problemCount; ++j) {
                cout << i.scoreList[j];
                if (j != problemCount - 1) {
                    cout << " ";
                }
            }
        }
    }
}