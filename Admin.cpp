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
}
void Admin::AddCourse(Course& c) {
   Course::courses[c.Name] = &c;
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
void Admin::EditCourse(Course& c){
   cout << "Choose what you want to edit : \n";
   cout << "1. Name\n2. Id\n3. Length\n";
   int choice;
   cin >> choice;
   if(choice == 1) {
    string newName;
    cin >> newName;
    if(Course::courses.find(newName) != Course::courses.end()) {
            cout << "Name already exists.\n";
            return;
    }
    Course::courses.erase(c.Name);
    c.Name = newName;
    Course::courses[c.Name] = &c;
    cout << "Updated\n";
  } else if(choice == 2) {
    string id;
    cin >> id;
    c.Id = id;
    cout << "Updated\n";
  } else if(choice == 3) {
    int length;
    cin >> length;
    c.Length = length;
    cout << "Updated\n";
   } else {
    cout << "Invalid\n";
   }
}