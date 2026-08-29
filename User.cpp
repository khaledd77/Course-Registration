#include "User.h"
#include "Course.h"
set<string> User::usernames;
set<string> User::passwords;
unordered_map<string, User*> User::users;
// NOTE !!!! WE NEED TO HANDLE THAT THE USER INPUTS A VALID USERNAME BEFORE WE INITIALIZE THE OBJECT
User::User(string firstName, string lastName, string userName, string password) {
    FirstName = firstName;
    LastName = lastName;
    UserName = userName;
    Password = password;
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
void User::SignOut(User*& u) {
    u = nullptr;
}
void User::EditData() {
    string arr[4] = {"firstName", "lastName", "userName", "password"};
    for(int i = 0; i < 4; i++) {
        char c;
        cout << "Do you want to change your " << arr[i] << " ? y/n" << "\n";
        cin >> c;
        if(c == 'y' || c == 'Y') {
            if(arr[i] == "userName" || arr[i] == "password") {
                cout << "Enter your new " << arr[i] << "\n";
                string s; 
                cin >> s;
                if(arr[i] == "userName" ) {
                    if(availableUsername(s)) {
                        usernames.erase(UserName);
                        users.erase(UserName);
                        UserName = s;
                        users[s] = this;
                        usernames.insert(UserName);
                        cout << "Updated\n";
                    }
                    else {
                        char cc;
                        while(!availableUsername(s)) {
                            cout << "Unavailable Username, would you like to enter again? y/n \n";
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
                           cout << "Updated\n";
                        }
                    }
                }
                if(arr[i] == "password" ) {
                    if(availablePass(s)) {
                       passwords.erase(Password);
                       Password = s;
                       passwords.insert(Password);
                       cout << "Updated\n";
                    }
                    else {
                        char cc;
                        while(!availablePass(s)) {
                            cout << "Unavailable Password, would you like to enter again? y/n \n";
                            cin >> cc;
                            if(cc == 'N' || cc == 'n') {
                                break;
                            }
                            cin >> s;
                        }
                       if(availablePass(s)) {
                          passwords.erase(Password);
                          Password = s;
                          passwords.insert(Password);
                          cout << "Updated\n";
                        }
                    }
                }
            } else {
                if(arr[i] == "firstName") {
                    string s;
                    cin >> s;
                    FirstName = s;
                } else if(arr[i] == "lastName") {
                    string s; cin >> s;
                    LastName = s;
                }

            }
        }

    }
}
bool User::availableUsername(string username)
{
    return usernames.find(username) == usernames.end();
}

bool User::availablePass(string password)
{
    return passwords.find(password) == passwords.end();
}
Course* User::SearchCourse(string name)
{
    auto it = Course::courses.find(name);

    if (it == Course::courses.end())
        return nullptr;

    return it->second;
}
