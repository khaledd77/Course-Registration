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
    if(it == Course::courses.end()) {
        cout << "Course not found.\n";
        return;
    }
    Course* c = it->second;
    for(Student* s : c->Students) {
        s->courses.erase(c);
    }
    for(auto& p : Course::courses) {
        Course* other = p.second;
        other->Prerequisites.erase(
            remove(other->Prerequisites.begin(), other->Prerequisites.end(), c),
            other->Prerequisites.end()
        );
    }
    Course::courses.erase(it);
    delete c;
    cout << "Course removed.\n";
}
void Admin::RemoveStudent(string username) {
    auto it = users.find(username);
    if(it == users.end() || !it->second->isStudent) {
        cout << "Student not found.\n";
        return;
    }
    Student* s = static_cast<Student*>(it->second);
    for(Course* c : s->courses) {
        c->Students.erase(
            remove(c->Students.begin(), c->Students.end(), s),
            c->Students.end()
        );
    }
    usernames.erase(s->UserName);
    passwords.erase(s->Password);
    users.erase(it);
    delete s;
    cout << "Student removed.\n";
}
void Admin::ManageGrades(Student& s, Course& c, int grade) {
    bool isreg = false;
    for(auto &i : c.Students) {
        if(i == &s) {
            isreg = true;
        }
    }
    if(isreg) {
        s.grades[c.Name] = grade;
        cout << "UPDATED!\n";
    }
    else 
    cout << "This student isn't registered in this course.\n";
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
    bool first = 1;
    cout << "Courses to select : ";
    for(auto i : Course::courses) {
        if(i.second == &c) {
            continue;
        }
        if(!first) cout << ", ";
        cout << i.first;
        first = 0;
    }
    cout << ".\n";
    string name;
    cout << "Enter prerequisite course name (-1 to stop):\n";
    while(getline(cin, name) && name != "-1")
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
void Admin::EditCourse(Course& c){
   cout << "Choose what you want to edit :- \n";
   cout << "1. Name\n";
   cout << "2. Length\n";
   int choice;
   cout << "Enter your choice : ";
   cin >> choice;
   if(choice == 1) {
    string newName;
    cin >> newName;
    if(Course::courses.find(newName) != Course::courses.end()) {
            cout << "Name already exists.\n";
            return;
    }
    string old = c.Name;
    for(Student* s : c.Students) {
       auto it = s->grades.find(old);
       if(it != s->grades.end()) {
        int grade = it->second;
        s->grades.erase(it);
        s->grades[newName] = grade;
       }
    }
    Course::courses.erase(c.Name);
    c.Name = newName;
    Course::courses[c.Name] = &c;
    cout << "Updated!\n";
  } else if(choice == 2) {
    int length;
    cin >> length;
    c.Length = length;
    cout << "Updated!\n";
   } else {
    cout << "Invalid.\n";
   }
}