#pragma once
#include<bits/stdc++.h>
using namespace std;
class Course;
class User {
 protected :
  string FirstName;
  string LastName;
  string UserName;
  string Password;
  bool loggedIn;
  static set<string>usernames;
  static set<string>passwords;
  static unordered_map<string, User*> users;
 public : 
  User(string firstName, string lastName, string userName, string password);
  void EditData(); // done
  void SignIn();
  void SignOut();
  Course* SearchCourse(string name); // potential problem
 private :
 bool availablePass(string ); // done
 bool availableUsername(string ); // done
};