#pragma once
#include <bits/stdc++.h>
using namespace std;
class Student;
class Admin;
 
class Course {
  friend class Admin;
  friend class Student;
  protected :
  string Id;  
  int Length;
  vector<Student*> Students;
  vector<Course*>Prerequisites;
  public :
  Course(string, string, int);
  string Name;
  static unordered_map<string, Course*> courses;
  void EditCourse(Course& c);
};