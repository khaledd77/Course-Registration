#pragma once
#include "User.h"
class Course;

class Student : public User {
 protected :
  unordered_map<string, int>grades;
  unordered_set<Course*>courses;
 public :
 Student(string firstName, string lastName, string userName, string password);
 void ViewGrades();
 void AddCourse(Course& c);
 void Report();
 void DropCourse(Course& c);
 void ViewRegCourses();
};