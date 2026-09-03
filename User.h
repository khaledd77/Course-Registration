#pragma once
#include<bits/stdc++.h>
using namespace std;
class Course;
class User {
    friend class Admin;
protected :
 string UserName;
 string Password;
 static set<string>usernames;
 static set<string>passwords;
 static unordered_map<string, User*> users;
public : 
 bool isStudent;
 string FirstName;
 string LastName;
 User(string firstName, string lastName, string userName, string password, bool);
  void EditData(); // done
  static User* SignIn(string, string); // done
  Course* SearchCourse(string name); // done
  static bool ValidPass(string ); // done
  static bool availableUsername(string ); // done
};