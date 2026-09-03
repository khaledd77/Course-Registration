#include "Admin.h"
#include "Student.h"
#include "Course.h"
unordered_map<string, Course*> Course::courses;
Course::Course(string name, int length) {
    Name = name;
    Length = length;
    courses[Name] = this;
}
void Course::ViewPre() {
    if(Prerequisites.empty()) {
        cout << "No prerequisites.\n";
        return;
    }
    cout << "Courses : ";
    bool first = 1;
    for(auto i : Prerequisites) {
        if(!first) cout << ", ";
        cout << i->Name;
        first = 0;
    }
    cout <<".\n";
}
void Course::ViewStudents() {
    if(Students.empty()) {
        cout << "No students.\n";
        return;
    }
    cout << Name << " Students :- \n";
    bool first = true;
    for(auto i : Students) {
        if(!first) {
            cout << ", ";
        }
        cout << i->FirstName << " " << i->LastName;
        first = false;
    }
    cout << ".\n";
}