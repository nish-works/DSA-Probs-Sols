#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{
    string subj;
    int id;
};

bool myComp(Student a, Student b)
{
    return (a.subj < b.subj);
}

int main()
{
    // Student stud[] = {{"CS", 100}, {"ECE", 102}, {"ECE", 100}, {"CS", 100}, {"CS", 99}, {"ECE", 105}};
    Student stud[] = {{"CS", 100}, {"ECE", 102}, {"ECE", 105}, {"CS", 101}, {"CS", 99}, {"ECE", 100}, {"CS", 100}};

    int n = sizeof(stud) / sizeof(stud[0]);
    stable_sort(stud, stud + n, myComp);
    for (auto it : stud)
        cout << it.subj << " " << it.id << endl;
    return 0;
}
