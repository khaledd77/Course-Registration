#include "User.h"
#include "Course.h"
set<string> User::usernames;
set<string> User::passwords;
unordered_map<string, User*> User::users;
// NOTE !!!! WE NEED TO HANDLE THAT THE USER INPUTS A VALID USERNAME BEFORE WE INITIALIZE THE OBJECT
User::User(string firstName, string lastName, string userName, string password, bool student) {
    FirstName = firstName;
    LastName = lastName;
    UserName = userName;
    Password = password;
    isStudent = student;
    usernames.insert(UserName);
    passwords.insert(Password);
    users[userName] = this;
}
User* User::SignIn(string userN, string pass) {
  auto it = users.find(userN);
  if(it == users.end()) {
    cout << "Username not found.\n";
    return nullptr;
   }
   User* user = it->second;
   if(user->Password != pass) {
    cout << "Password incorrect. \n";
    return nullptr;
   }
   cout << "Signed in successfully. \n";
   return user;
}
void User::EditData() {
    cout << "Choose the data you wish to edit :\n";
    cout << "1. First Name\n";
    cout << "2. Last Name\n";
    cout << "3. UserName\n";
    cout << "4. Password\n";
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;
    if(choice == 1) {
        cout << "Enter your new first name : ";
        string s;
        cin >> s;
        FirstName = s;
    } else if(choice == 2) {
        cout << "Enter your new last name : ";
        string s; 
        cin >> s;
        LastName = s;
    } else if(choice == 3) {
        cout << "Enter your new username : ";
        string s; 
        cin >> s;       
        if(availableUsername(s)) {
           usernames.erase(UserName);
           users.erase(UserName);
           UserName = s;
           users[s] = this;
           usernames.insert(UserName);
           cout << "Updated!\n";
        } else {
            char cc;
            while(!availableUsername(s)) {
                cout << "Unavailable Username, would you like to enter again? y/n : ";
                cin >> cc;
                if(cc == 'N' || cc == 'n') {
                    break;
                }
                cin >> s;
            }
            if(availableUsername(s)) {
               usernames.erase(UserName);
               users.erase(UserName);
               UserName = s;
               users[s] = this;
               usernames.insert(UserName);
               cout << "Updated!\n";
            }
        }
    } else if(choice == 4) {
        cout << "Enter your new password : ";
        string s; 
        cin >> s;
        if(ValidPass(s)) {
           passwords.erase(Password);
           Password = s;
           passwords.insert(Password);
           cout << "Updated\n";
        } else {
           char cc;
           while(!ValidPass(s)) {
               cout << "Unavailable Password, would you like to enter again? y/n : ";
               cin >> cc;
               if(cc == 'N' || cc == 'n') {
                   break;
               }
               cin >> s;
           }
           if(ValidPass(s)) {
              passwords.erase(Password);
              Password = s;
              passwords.insert(Password);
              cout << "Updated!\n";
            }
        }
    } else {
        cout << "INVALID\n";
    }
}


bool User::availableUsername(string username)
{
    return usernames.find(username) == usernames.end();
}

bool User::ValidPass(string password)
{
    return password.length() >= 8;
}
Course* User::SearchCourse(string name)
{
    auto it = Course::courses.find(name);

    if (it == Course::courses.end())
        return nullptr;

    return it->second;
}
