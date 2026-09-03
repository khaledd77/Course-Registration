#include<bits/stdc++.h>
#include "User.cpp"
#include "Student.cpp"
#include "Admin.cpp"
#include "Course.cpp"
using namespace std;
void goStudent(Student* s);
void goAdmin(Admin* s);
void pause();
int main() {
    cout << "---------------------Welcome to Course Registeration---------------------\n";
    while(true) {
        cout << "1. Register\n";
        cout << "2. Sign In\n";
        cout << "3. Exit\n";
        int choice;
        cout << "Enter your choice : ";
        cin >> choice;
        if(choice == 3) break;
        if(choice == 1) {
            cout << "1. Student\n";
            cout << "2. Admin\n";
            cout << "Enter your choice : ";
            cin >> choice;
            if(choice == 1) {
               string firstname, lastname, username, password;
               cout << "Enter your first name : ";
               cin >> firstname;
               cout << "Enter your last name : ";
               cin >> lastname;
               while(true) {
                cout << "Enter your username: ";
                cin >> username;
                if(User::availableUsername(username)) break;
                 cout << "Username already exists. Try another one.\n";
                }
               while(true) {
                cout << "Set your password(8 minimum) : ";
                cin >> password;
                if(User::ValidPass(password)) break;
                cout << "Password not valid. Try another one.\n";
               }
               Student* s = new Student(firstname, lastname, username, password);
               cout << "Student created, please sign in\n";
            } else if(choice == 2) {
               string firstname, lastname, username, password;
               cout << "Enter your first name : ";
               cin >> firstname;
               cout << "Enter your last name : ";
               cin >> lastname;
               while(true) {
                cout << "Enter your username: ";
                cin >> username;
                if(User::availableUsername(username)) break;
                 cout << "Username already exists. Try another one.\n";
                }
               while(true) {
                cout << "Set your password(8 minimum) : ";
                cin >> password;
                if(User::ValidPass(password)) break;
                cout << "Password not valid. Try another one.\n";
               }
               Admin* a = new Admin(firstname, lastname, username, password);
               cout << "Admin created, please sign in\n";
            } else {
                cout << "INVALID\n";
            }
            pause();
        } else if(choice == 2) {
            cout << "Please enter your username and password to sign in\n";
            string username, pass;
            cout << "username : "; cin >> username; 
            cout << "password : "; cin >> pass; 
            User* currentUser = User::SignIn(username, pass);
            if(currentUser == nullptr) {
                cout << "Wrong, Please try again\n";
                continue;
            }
            if(currentUser->isStudent) {
                Student* student = static_cast<Student*>(currentUser);
                pause();
                goStudent(student);
            } else {
                Admin* admin = static_cast<Admin*>(currentUser);
                pause();
                goAdmin(admin);
            }
            
            pause();
        }
    }
    return 0;
}
void goStudent(Student* s) {
    cout << "\n========== Student Menu ==========\n";
    while(true) {
        cout << "1. View Grades\n";
        cout << "2. Check course prerequistes \n";
        cout << "3. Register Course\n";
        cout << "4. Drop Course\n";
        cout << "5. View Registered Courses\n";
        cout << "6. Edit Data\n";
        cout << "7. Report \n";
        cout << "8. Sign Out\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if(choice == 1) {
            s->ViewGrades();
            pause();
        } else if(choice == 2) {
            cout << "Enter the name of the course: ";
            string name;
            cin.ignore();
            getline(cin, name);
            Course* c = s->SearchCourse(name);
            if(c == nullptr) {
              cout << "Course not found.\n";
            } else {
              cout << "Prerequisites for " << c->Name << ":\n";
              c->ViewPre();
              if(s->CheckPre(*c))
                cout << "You can register for this course.\n";
              else
                cout << "You cannot register for this course.\n";
            }
            pause();
        } else if(choice == 3) {
            cout << "Enter the name of the course you want to register : ";
            string name; 
            cin.ignore();
            getline(cin, name);
            Course* c = s->SearchCourse(name);
            if(c == nullptr) {
                cout << "Course not found.\n";
            } else {
                s->AddCourse(*c);
            }
            pause();
        } else if(choice == 4) {
            cout << "Enter the name of the course you want to drop : ";
            string name;
            cin.ignore();
            getline(cin, name);
            Course* c = s->SearchCourse(name);
            if(c == nullptr) {
                cout << "Course not found. \n";
            } else {
                s->DropCourse(*c);
            }
            pause();
        } else if(choice == 5) {
            s->ViewRegCourses();
            pause();
        } else if(choice == 6) {
            s->EditData();
            pause();
        } else if(choice == 7) {
            s->Report();
            pause();
        } else if(choice == 8) {
            cout << "Signed out successfully.\n";
            break;
        } else {
            cout << "INVALID\n";
            pause();
        }
    }

}
void goAdmin(Admin* a) {
    

}
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}