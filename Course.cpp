#include "Admin.h"
#include "Student.h"
#include "Course.h"
unordered_map<string, Course*> Course::courses;
Course::Course(string name, string id, int length) {
    Name = name;
    Id = id;
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
    for(auto i : Students) {
        cout << i->FirstName << " " << i->LastName << ", ";
    }
    cout << "\n";
}