#include "Admin.h"
#include "Student.h"
#include "Course.h"
Admin::Admin(string firstName, string lastName,
                 string userName, string password)
    : User(firstName, lastName, userName, password, false)
{
}
void Admin::RemoveCourse(string name) {
    auto it = Course::courses.find(name);
    if(it != Course::courses.end()) {
        Course::courses.erase(it);
    }
}
void Admin::AddCourse(Course& c) {
   Course::courses[c.Name] = &c;
}
void Admin::RemoveStudent(string username) {
    users.erase(username);
}
void Admin::ManageGrades(Student& s, Course& c, int grade) {
    s.grades[c.Name] = grade;
}
Student* Admin::SearchStudent(string username) {
    auto it = users.find(username);
    if(it == users.end() || !it->second->isStudent) {
        cout << "Not found ! \n";
        return nullptr;
    }
    return static_cast<Student*>(it->second);
}
void Admin::SetPre(Course& c) {
    for(auto i : Course::courses) {
        cout << i.first <<", ";
    }
    cout << "\n";
    string name;
    cout << "Enter prerequisite course name (-1 to stop):\n";
    while(cin >> name && name != "-1")
    {
        auto it = Course::courses.find(name);
        if(it == Course::courses.end()) {
            cout << "Course not found.\n";
            continue;
        }
        c.Prerequisites.push_back(it->second);
        cout << "Prerequisite added.\n";
    }
}