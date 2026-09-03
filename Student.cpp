#include "Course.h"
#include "Student.h"
Student::Student(string firstName, string lastName,
                 string userName, string password)
    : User(firstName, lastName, userName, password, true)
{
}
void Student::ViewGrades() {
    if(grades.empty()) {
        cout << "No grades to show\n";
        return;
    }
    for(auto i : grades) {
        cout << i.first << ": " << i.second << "\n";
    }
}
void Student::AddCourse(Course& c) {
    if(courses.find(&c) != courses.end()) {
        cout << "You are already registered in this course.\n";
        return;
    }
    if(CheckPre(c) == 0) {
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
    cout << "Registered courses :- \n";
    if(courses.empty()) {
        cout << "There are no courses to show.\n";
        return; 
    }
    bool first = 1;
    bool worked = 0;
    for(auto i : courses) {
        if(!first) cout << ", ";
        cout << i->Name;
        first = 0;
        worked = 1;
    }
    if(worked) cout << ".\n";
    cout << "Grades :- \n";
    if(grades.empty()) {
        cout << "There are no grades to show.\n";
        return;
    }
    for(auto i : grades) {
        cout << i.first << ": " << i.second << endl;
    }
}
void Student::DropCourse(Course& c) {
     if(courses.find(&c) == courses.end()) {
        cout << "You are not registered in this course.\n";
        return;
    }
    courses.erase(&c);
     c.Students.erase(
        remove(c.Students.begin(), c.Students.end(), this),
        c.Students.end()
    );
    cout << "Course dropped successfully.\n";
}
void Student::ViewRegCourses() {
    if(courses.empty()) {
        cout << "There are no courses to show\n";
        return;
    }
    cout << "Registered courses : \n";
    for(auto i : courses) {
        cout << i->Name << endl;
    }
}
int Student::CheckPre(Course& c) {
    if(courses.find(&c) != courses.end()) {
        return 2;
    }
    for(Course* pre : c.Prerequisites)
    {
        auto it = grades.find(pre->Name);

        if(it == grades.end() || it->second < 60) return 0;
        
    }

    return 1;
}