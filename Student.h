#pragma once
#include "User.h"
class Course;

class Student : public User {
    friend class Admin;
 protected :
 unordered_set<Course*>courses;
 public :
 Student(string firstName, string lastName, string userName, string password);
 unordered_map<string, int>grades;
 void ViewGrades();
 void AddCourse(Course& c);
 void Report();
 void DropCourse(Course& c);
 void ViewRegCourses();
 int CheckPre(Course& c);
};