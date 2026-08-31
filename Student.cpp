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
    if(courses.find(&c) != courses.end()) {
        cout << "You are already registered in this course.\n";
        return;
    }
    if(!CheckPre(c)) {
        cout << "You are not eligible for this course.\n";
        return;
    }
    courses.insert(&c);
    c.Students.push_back(this);
    cout << "Course added successfully\n";
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
     c.Students.erase(
        remove(c.Students.begin(), c.Students.end(), this),
        c.Students.end()
    );
}
void Student::ViewRegCourses() {
    cout << "Registered courses : \n";
    for(auto i : courses) {
        cout << i->Name << endl;
    }
}
bool Student::CheckPre(Course& c) {
    for(Course* pre : c.Prerequisites)
    {
        auto it = grades.find(pre->Name);

        if(it == grades.end() || it->second < 60)
        {
            return false;
        }
    }

    return true;
}