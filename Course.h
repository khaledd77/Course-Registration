#pragma once
#include <bits/stdc++.h>
using namespace std;
class Student;
 
class Course {
 protected :
  string Name;
  string Id;  
  int Length;
  vector<Course*>Prerequisites;
  vector<Student*> Students;
 public :
  void EditCourse(Course& c);
};