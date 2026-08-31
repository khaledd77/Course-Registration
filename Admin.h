#pragma once
#include "User.h"
class Student;
class Course;

class Admin : public User {
 public :
  void RemoveCourse(Course& c);
  void AddCourse(Course& c);
  vector<Course*> SetPre();
  void RemoveStudent(Student& s);
  void ManageGrades(Student& s, Course& c, int grade);
  Student* SearchStudent(string username);
};