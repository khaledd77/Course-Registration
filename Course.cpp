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
    for(auto i : Prerequisites) {
        cout << i->Name << " ";
    }
    cout << endl;
}
void Course::ViewStudents() {
    if(Students.empty()) {
        cout << "No students\n";
        return;
    }
    cout << Name << " Students : \n";
    for(auto i : Students) {
        cout << i->FirstName << " " << i->LastName << ", ";
    }
    cout << "\n";
}