#pragma once
#include "User.h"
class Course;

class Student : public User {
 protected :
  unordered_map<string, int>grades;
  vector<Course*>courses;
 public :
 void ViewGrades();
 void Report();
 void DropCourse(Course& c);
 void ViewRegCourses();
};