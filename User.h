#pragma once
#include<bits/stdc++.h>
using namespace std;
class Course;
class User {
 protected :
  string FirstName;
  string LastName;
  string Id;
  string UserName;
  string Password;
 public : 
  void EditData();
  void SignIn();
  void SignOut();
  Course* SearchCourse(string name);
};