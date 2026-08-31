#pragma once
#include <bits/stdc++.h>
using namespace std;
class Student;
 
class Course {
 public :
  string Name;
  string Id;  
  int Length;
  vector<Course*>Prerequisites;
  vector<Student*> Students;
  public :
  static unordered_map<string, Course*> courses;
  void EditCourse(Course& c);
};