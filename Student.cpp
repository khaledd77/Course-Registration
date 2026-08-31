#include "Course.h"
#include "Student.h"
Student::Student(string firstName, string lastName,
                 string userName, string password)
    : User(firstName, lastName, userName, password, true)
{
}
void Student::ViewGrades() {
    for(auto i : grades) {
        cout << i.first << ": " << i.second << "\n";
    }
}
void Student::AddCourse(Course& c) {
    courses.insert(&c);
}
void Student::Report() {
    cout << "Student\n";
    cout << "Name : " ;
    cout << FirstName << " " <<  LastName << endl;
    cout << "Username : " << UserName << endl;
    cout << "Grades : \n";
    for(auto i : grades) {
        cout << i.first << ": " << i.second << endl;
    }
}
void Student::DropCourse(Course& c) {
    courses.erase(&c);
}
void Student::ViewRegCourses() {
    cout << "Registered courses : \n";
    for(auto i : courses) {
        cout << i->Name << endl;
    }
}