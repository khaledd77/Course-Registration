#include<bits/stdc++.h>
#include "User.cpp"
#include "Student.cpp"
#include "Admin.cpp"
#include "Course.cpp"
using namespace std;
void goStudent(Student* s);
void goAdmin(Admin* s);
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
                goStudent(student);
            } else {
                Admin* admin = static_cast<Admin*>(currentUser);
                goAdmin(admin);
            }
            
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
        } else if(choice == 2) {
            cout << "Enter the name of the course: ";
            string name;
            cin.ignore();
            getline(cin, name);
            Course* c = s->SearchCourse(name);
            if(c == nullptr) {
              cout << "Course not found.\n";
            } else {
              cout << "Prerequisite for " << c->Name << ":\n";
              c->ViewPre();
              int r = s->CheckPre(*c);
              if(r == 2) 
                cout << "You are already registered in this course.\n";
              else if(r == 1)
                cout << "You can register for this course.\n";
              else
                cout << "You cannot register for this course.\n";
            }
            
        } else if(choice == 3) {
            bool first = 1;
            cout << "Courses available : ";
            for(auto i : Course::courses) {
                if(!first) cout << ", ";
                cout << i.first;
                first = 0;
            }
            cout <<".\n";
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
            
        } else if(choice == 5) {
            s->ViewRegCourses();
        } else if(choice == 6) {
            s->EditData();
        } else if(choice == 7) {
            s->Report();
        } else if(choice == 8) {
            cout << "Signed out successfully.\n";
            break;
        } else {
            cout << "INVALID\n";
        }
    }

}
void goAdmin(Admin* a) {
    cout << "\n========== Admin Menu ==========\n";
    while(true) {
        cout << "1. Add Course\n";
        cout << "2. Remove Course\n";
        cout << "3. Set Prerequisite\n";
        cout << "4. Manage Grades\n";
        cout << "5. Remove Student\n";
        cout << "6. Edit Course\n";
        cout << "7. Edit Data\n";
        cout << "8. View course students\n";
        cout << "9. Sign Out\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if(choice == 1) {
            cout << "Enter the course name : ";
            string name;
            cin.ignore();
            getline(cin, name);
            if(a->SearchCourse(name) != nullptr) {
              cout << "Course already exists.\n";
              continue;
            }
            cout << "Enter the course hourse : ";
            int length; cin >> length;
            Course* c = new Course(name, length);
            cout << "Course added successfully!\n";
        } else if(choice == 2) {
            cout << "Enter the course name that you want to remove : ";
            string name;
            cin.ignore();
            getline(cin, name);
            a->RemoveCourse(name);
        } else if(choice == 3) {
            cout << "Enter the course name that you want to set the Prerequisite for :  ";
            string s;
            cin.ignore();
            getline(cin, s);
            Course* c  = a->SearchCourse(s);
            if(c == nullptr) {
              cout << "Course not found.\n";
              continue;
            }
            a->SetPre(*c);
        } else if(choice == 4) {
            while(true) {
                cout << "Enter the student username and the course name : \n";
                string username, name;
                cout << "Username : "; cin >> username;
                cout << "Name : ";
                cin.ignore();
                getline(cin, name);
                Student* s = a->SearchStudent(username);
                Course* c = a->SearchCourse(name);
                if(s == nullptr || c == nullptr) {
                    cout << "Wrong data, do you want to try again ? (y/n)\n";
                    char choice; cin >> choice;
                    if(choice == 'n' || choice == 'N') break;
                    else continue;
                }
                cout << "Enter the grade : ";
                int grade; cin >> grade;
                a->ManageGrades(*s, *c, grade);
                cout << "Do you want to exit grading ? y/n : ";
                char choice; cin >> choice;
                if(choice == 'y' || choice == 'Y') break;
            }
        } else if(choice == 5) {
            cout << "Enter the username of the student you want to remove : ";
            string s; cin >> s;
            a->RemoveStudent(s);
        } else if(choice == 6) {
            cout << "Enter the course name : ";
            string s;
            cin.ignore();
            getline(cin, s);
            Course* c = a->SearchCourse(s);
            if(c == nullptr) {
              cout << "Course not found.\n";
              continue;
            }
            a->EditCourse(*c);
        } else if(choice == 7) {
            a->EditData();
        } else if(choice == 8) {
            cout << "Enter course name : ";
            string name;
            cin.ignore();
            getline(cin, name);
            Course* c = a->SearchCourse(name);
            if(c == nullptr) {
                cout << "Course not found.\n";
                continue;
            }
            c->ViewStudents();
        } else if(choice == 9) {
            cout << "Signed out successfully.\n";
            break;
        } else {
            cout << "INVALID\n";
        }

    }
    
}
