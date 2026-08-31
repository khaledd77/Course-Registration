#pragma once
#include "User.h"
class Student;
class Course;

class Admin : public User {
 public :
 Admin(string firstName, string lastName, string userName, string password); // done
  void RemoveCourse(string name); // done
  void AddCourse(Course& c); // done
  void SetPre(Course& c); // done
  void RemoveStudent(string username); // done
  void ManageGrades(Student& s, Course& c, int grade); // done
  Student* SearchStudent(string username); // done
};