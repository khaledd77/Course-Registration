#pragma once
#include<bits/stdc++.h>
using namespace std;
class Course;
class User {
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
  User* SignIn(string, string); // done
  void SignOut(User*&); // We could make it in the main as a regular function
  Course* SearchCourse(string name); // done
 private :
 bool availablePass(string ); // done
 bool availableUsername(string ); // done
};